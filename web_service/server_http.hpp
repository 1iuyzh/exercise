#ifndef SERVER_HTTP_HPP
#define SERVER_HTTP_HPP

#include <boost/asio.hpp>
#include "server_base.hpp"

#include <memory>

namespace Web {

typedef boost::asio::ip::tcp::socket HTTP;

//模板特例化
template <>
class Server<HTTP> : public ServerBase<HTTP> {
public:
    Server(unsigned short port) : ServerBase<HTTP>::ServerBase(port) {}

private:
    //accept方法, 不能放在线程池里
    void accept() {
        //为当前连接创建一个新的socket
        auto socket = std::make_shared<HTTP>(m_io_service);

        //连接
        acceptor.async_accept(*socket, [this, socket](const boost::system::error_code& ec) {
            //接受一个连接
            accept();
            
            if (!ec)
                process_request_and_respond(socket);
        });
    }
};

}

#endif