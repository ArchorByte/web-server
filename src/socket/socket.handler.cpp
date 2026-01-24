#include "socket.hpp"

#include <iostream>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>

/*
    Create and deploy a socket server.

    Tasks:
        1) Verify function parameters.
        2) Try to initialize the socket.
        3) Try to bind the socket to an address.
        4) Try to make the socket listen the specified address on the specified port.

    Parameters:
        - address       / string / IP address or domain name to run the socket on.
        - port          / int    / Port to listen.
        - server_socket / int    / Variable that will be modified to contain the created socket server.

    Returns:
        A boolean confirming whether we successfully created the socket server or not.
*/
bool Socket::create_socket_server
(
    const std::string &address,
    const int &port,
    int &server_socket
)
{
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    const bool initialization = server_socket >= 0;

    if (!initialization)
    {
        std::cerr << "Failed to initialize the web server socket!\n";
        return false;
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;

    const bool binding = bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) >= 0;

    if (!binding)
    {
        std::cerr << "Failed to bind the server address and the server socket!\n";
        return false;
    }

    const bool listening = listen(server_socket, 5) >= 0;

    if (!listening)
    {
        std::cerr << "Failed to listen port " << port << "!\n";
        return false;
    }

    std::cout << "Socket server up and listening at http://" << address << ":" << port << ".\n";
    return true;
}
