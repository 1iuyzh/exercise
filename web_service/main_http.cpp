#include <iostream>
#include "server_http.hpp"
#include "handler.hpp"

using namespace Web;

int main() {
    Server<HTTP> server(8000);
    std::cout << "Server starting at port: 8000" << std::endl;
    start_server(server);
    return 0;
}