#ifndef SERVER_BASE_HPP
#define SERVER_BASE_HPP

#include <boost/asio.hpp>

#include "thread_pool.h"
#include <iostream>
#include <regex>
#include <unordered_map>
#include <thread>
#include <memory>
#include <string>
#include <vector>
#include <functional>
#include <map>

namespace Web {

//请求信息结构体
struct Request {
    //请求方法, POST, GET; 请求路径; HTTP版本
    std::string method, path, http_version;
    //对content使用智能指针进行引用计数
    std::shared_ptr<std::istream> content;
    //Key-value
    std::unordered_map<std::string, std::string> header;
    //用正则表达式处理路径匹配
    std::smatch path_match;
};

//server.resource["^/info/?$"]["GET"] = [](){...}
typedef std::map<std::string, std::unordered_map<std::string, 
    std::function<void(std::ostream&, Request&)>>> resource_type;

//socket_type为HTTP或HTTPS
template <typename socket_type>
class ServerBase {
public:
    //用于服务器访问资源处理方式
    resource_type resource;
    //用于保存默认资源的处理方式
    resource_type default_resource;

    //启动服务器
    void start();

protected:
    //用于内部实现对所有资源的处理
    std::vector<resource_type::iterator> all_resources;

    //asio库中的io_service是调度器, 所有异步IO事件都需要它分发处理
    //需要IO的对象的构造函数, 都需要传入一个io_service对象
    boost::asio::io_service m_io_service;
    //IP地址, 端口号, 协议版本构成一个endpoint
    //服务端根据endpoint生成tcp::acceptor对象, 并在指定端口等待连接
    boost::asio::ip::tcp::endpoint endpoint;
    //acceptor对象的构造需要io_service和endpoint两个参数
    boost::asio::ip::tcp::acceptor acceptor;

    //线程池
    thread_pool pool;
    
    //不同类型服务器实现方法不同
    virtual void accept() {}
    //处理请求和应答
    void process_request_and_respond(std::shared_ptr<socket_type> socket) const;
    //解析请求
    Request parse_request(std::istream& stream) const;
    //应答
    void respond(std::shared_ptr<socket_type> socket, std::shared_ptr<Request> request) const;

public:
    ServerBase(unsigned short port) : endpoint(boost::asio::ip::tcp::v4(), port),
        acceptor(m_io_service, endpoint) {}
};

template <typename socket_type>
class Server : public ServerBase<socket_type> {};

template <typename socket_type>
void ServerBase<socket_type>::start() {
    //默认资源放在vector结尾, 用作默认应答
    for (auto it = resource.begin(); it != resource.end(); it++) {
        all_resources.push_back(it);
    }
    for (auto it = default_resource.begin(); it != default_resource.end(); it++) {
        all_resources.push_back(it);
    }

    //调用socket的连接方式, 需要子类实现accept()逻辑
    //HTTP和HTTPS在处理请求和返回请求的唯一区别在于如何处理与客户端建立连接的方式
    accept(); //调用process_request_and_respond()函数
    
    /*
    for (size_t i = 0; i < std::thread::hardware_concurrency(); i++) {
        pool.submit([this]{ m_io_service.run(); });
    }
    */
}

template <typename socket_type>
void ServerBase<socket_type>::process_request_and_respond(std::shared_ptr<socket_type> socket) const {
    //为async_read_until()创建新的读缓存
    //shared_ptr用于传递临时对象给匿名函数
    auto read_buffer = std::make_shared<boost::asio::streambuf>();

    boost::asio::async_read_until(*socket, *read_buffer, "\r\n\r\n", 
    [this, socket, read_buffer](const boost::system::error_code& ec, size_t bytes_transferred) {
        if (!ec) {
            //read_buffer->size()并不一定和bytes_transferred相等
            //async_read_until成功后, streambuf在界定符之外可能包含一些额外的数据
            //从流中提取并解析当前read_buffer左边的报头, 再拼接async_read后面的内容
            size_t total = read_buffer->size();
            
            //转换到istream
            std::istream stream(read_buffer.get());

            //提取Request
            auto request = std::make_shared<Request>();
            *request = parse_request(stream);

            size_t num_additional_bytes = total-bytes_transferred; //多余字节数

            if (request->header.count("Content-Length") > 0) {
                boost::asio::async_read(*socket, *read_buffer,
                //拼接剩余字节
                boost::asio::transfer_exactly(std::stoull(request->header["Content-Length"]) - num_additional_bytes),
                [this, socket, read_buffer, request](const boost::system::error_code& ec, size_t bytes_transferred) {
                    if (!ec) {
                        //更新request.content
                        request->content = std::shared_ptr<std::istream>(new std::istream(read_buffer.get()));
                        respond(socket, request);
                    }
                });
            } else {
                respond(socket, request);
            }
        }
    });
}

template <typename socket_type>
Request ServerBase<socket_type>::parse_request(std::istream& stream) const {
    Request request;

    //解析出请求方法, 请求路径以及HTTP版本
    std::regex e("^([^ ]*) ([^ ]*) HTTP/([^ ]*)$");

    std::smatch sub_match;

    //从第一行中解析请求方法, 路径和HTTP版本
    std::string line;
    getline(stream, line);
    line.pop_back();
    if (std::regex_match(line, sub_match, e)) {
        request.method = sub_match[1];
        request.path = sub_match[2];
        request.http_version = sub_match[3];

        //解析头部的其他信息
        bool matched;
        e = "^([^:]*): ?(.*)$";
        do {
            getline(stream, line);
            line.pop_back();
            matched = std::regex_match(line, sub_match, e);
            if (matched)
                request.header[sub_match[1]] = sub_match[2];
        } while (matched == false);
    }
    return request;
};

template <typename socket_type>
void ServerBase<socket_type>::respond(std::shared_ptr<socket_type> socket, std::shared_ptr<Request> request) const {
    for (auto res_it : all_resources) {
        std::regex e(res_it->first);
        std::smatch sm_res;
        if (std::regex_match(request->path, sm_res, e)) {
            if (res_it->second.count(request->method) > 0) {
                request->path_match = move(sm_res);

                auto write_buffer = std::make_shared<boost::asio::streambuf>();
                std::ostream response(write_buffer.get());
                res_it->second[request->method](response, *request); //调用方法, 将响应写到response内

                boost::asio::async_write(*socket, *write_buffer,
                [this, socket, request, write_buffer](const boost::system::error_code& ec, size_t bytes_transffered) {
                    //递归调用
                    if (!ec && std::stof(request->http_version) > 1.05)
                        process_request_and_respond(socket);
                });
                return;
            }
        }
    }
}

}

#endif