#ifndef APP_SOCKET_HPP
#define APP_SOCKET_HPP

#include <string>

namespace Socket
{
    ////////////////////////
    ///// requests.cpp /////
    ////////////////////////

    void handle_request
    (
        const int &client
    );

    //////////////////////////////
    ///// socket.handler.cpp /////
    //////////////////////////////

    bool create_socket_server
    (
        const std::string &address,
        const int &port,
        int &server_socket
    );
}

#endif
