#ifndef SERVER_HTTPS_HPP
#define SERVER_HTTPS_HPP

#include "server_http.hpp"
#include <boost/asio/ssl.hpp>

namespace Web {

typedef boost::asio::ssl::stream<boost::asio::ip::tcp::socket> HTTPS;

template <>
class Server<HTTPS> : public ServerBase<HTTPS> {
public:
    //增加了两个参数, 一个是证书文件, 一个是密钥文件
    Server(unsigned short port, const std::string& cert_file, const std::string& private_key_file) :
    ServerBase<HTTPS>::ServerBase(port), context(boost::asio::ssl::context::sslv23) {
        context.use_certificate_chain_file(cert_file);
        context.use_private_key_file(private_key_file, boost::asio::ssl::context::pem);
    }

private:
    boost::asio::ssl::context context;

    void accept {
        auto socket = std::make_shared<HTTPS>(m_io_service, context);

        acceptor.async_accept(
            (*socket).lowest_layer(),
            [this, socket](const boost::system::error_code& ec) {
                accept();
                // 处理错误
                if(!ec) {
                    (*socket).async_handshake(boost::asio::ssl::stream_base::server,
                    [this, socket](const boost::system::error_code& ec) {
                        if(!ec)
                            process_request_and_respond(socket);
                    });
                }
            });
    }
};

}

#endif