#include "server_base.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <ios>

using namespace Web;

template <typename SERVER_TYPE>
void start_server(SERVER_TYPE& server) {
    //向服务器增加请求资源的处理方法

    server.resource["^/string/?$"]["POST"] = [](std::ostream& response, Request& request) {
        std::stringstream ss;
        *request.content >> ss.rdbuf(); //rdbuf()获得底层streambuf对象指针
        std::string content = ss.str();

        response << "HTTP/1.1 200 OK\r\nContent-Length: " << content.length() << "\r\n\r\n" << content;
    };

    server.resource["^/info/?$"]["GET"] = [](std::ostream& response, Request& request) {
        std::stringstream content_stream;
        content_stream << "<h1>Request:</h1>";
        content_stream << request.method << " " << request.path << " HTTP/" << request.http_version << "<br>";
        for(auto& header: request.header) {
            content_stream << header.first << ": " << header.second << "<br>";
        }
        
        //获得content_stream的长度, 使用tellp()获得
        content_stream.seekp(0, std::ios::end); //设置文件流指针位置

        response <<  "HTTP/1.1 200 OK\r\nContent-Length: " << content_stream.tellp() << "\r\n\r\n" << content_stream.rdbuf();
    };

    //例如执行请求GET /match/abc, 将返回abc
    server.resource["^/match/([0-9a-zA-Z]+)/?$"]["GET"] = [](std::ostream& response, Request& request) {
        std::string number = request.path_match[1];
        response << "HTTP/1.1 200 OK\r\nContent-Length: " << number.length() << "\r\n\r\n" << number;
    };

    //处理默认GET请求, 如果没有其他匹配成功, 则这个匿名函数会被调用
    //将应答web/目录及其子目录中的文件
    //默认文件: index.html
    server.default_resource["^/?(.*)$"]["GET"] = [](std::ostream& response, Request& request) {
        std::string filename = "web/";

        std::string path = request.path_match[1];

        // 防止使用 `..` 来访问web/目录外的内容
        size_t last_pos = path.rfind(".");
        size_t current_pos = 0;
        size_t pos;
        while ((pos = path.find('.', current_pos)) != std::string::npos && pos != last_pos) {
            current_pos = pos;
            path.erase(pos, 1);
            last_pos--;
        }

        filename += path;
        std::ifstream ifs;
        //简单的平台无关的文件或目录检查
        if (filename.find('.') == std::string::npos) {
            if (filename[filename.length() - 1] != '/')
                filename += '/';
            filename += "index.html";
        }
        ifs.open(filename, std::ifstream::in);

        if(ifs) {
            ifs.seekg(0, std::ios::end);
            size_t length = ifs.tellg();

            ifs.seekg(0, std::ios::beg);

            //文件内容拷贝到response stream中, 不应该用于大型文件
            response << "HTTP/1.1 200 OK\r\nContent-Length: " << length << "\r\n\r\n" << ifs.rdbuf();

            ifs.close();
        } else {
            //文件不存在时, 返回无法打开文件
            std::string content = "Could not open file " + filename;
            response << "HTTP/1.1 400 Bad Request\r\nContent-Length: " << content.length() << "\r\n\r\n" << content;
        }
    };

    server.start();
}