#include "src/app.hpp"

#include <iostream>
#include <netinet/in.h>
#include <map>
#include <stdexcept>
#include <string>
#include <sys/socket.h>
#include <thread>

/*
    Main function of the program.

    Tasks:
        1) Parse the config file.
        2) Verify the retrieved data.
        3) Start a socket server.
        4) Create a thread for each request to treat.

    Parameters:
        No parameters.

    Returns:
        An integer representing a success or error code.
*/
int main()
{
    std::cout << "The web server is booting up..\n";

    App::Routes::register_routes();
    std::map<std::string, std::string> config = App::Utils::Parsers::parse_config_file("socket.config");

    const std::string address = config["ADDRESS"];
    std::string port = config["PORT"];

    if (!Utils::Text::is_an_integer(port))
    {
        std::cerr << "The retrieved port from the config file is not valid!";
        port = "8080";
    }

    int server_socket;
    const bool socket_creation = App::Socket::create_socket_server(address, std::stoi(port), server_socket);

    if (!socket_creation)
    {
        std::cerr << "Failed to create the socket server!\n";
        exit(-1);
    }

    while (true)
    {
        struct sockaddr_in client_address;
        socklen_t request_size = sizeof(client_address);

        int client = accept(server_socket, (struct sockaddr*) &client_address, &request_size);
        const bool client_acceptation = client >= 0;

        if (!client_acceptation)
        {
            std::cerr << "Warning: Failed to accept the client!\n";
            continue;
        }

        std::thread client_thread(App::Socket::handle_request, client);
        client_thread.detach();
    }

    std::cout << "Web server stopped successfully!\n";
    return 0;
}
