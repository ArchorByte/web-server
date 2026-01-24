#include "socket.hpp"

#include "../routes/routes.hpp"

#include <cstddef>
#include <iostream>
#include <sstream>
#include <unistd.h>

/*
    Handle an HTTP request.

    Tasks:
        1) Read the data of the request made by the client with a buffer.
        2) Convert it to string to make it easier to work with.
        3) Get the first line that contains the essential request information.
        4) Retrieve the data from it (method, HTTP version, and requested path).
        5) Log it, and reply a simple hello world.

    Parameters:
        - client / int / Request data provided by the client.

    Returns:
        No object returned.
*/
void Socket::handle_request
(
    const int &client
)
{
    char buffer[2048];
    const int bytes_read = read(client, buffer, sizeof(buffer) - 1);

    if (bytes_read <= 0)
    {
        close(client);
        return;
    }

    const std::string request(buffer, bytes_read);
    const size_t first_line_end = request.find("\r\n");

    if (first_line_end == std::string::npos)
    {
        std::string response = "HTTP/1.1 400 Bad Request\r\n\r\n";
        write(client, response.c_str(), response.size());
        close(client);
        return;
    }

    const std::string first_line = request.substr(0, first_line_end);
    std::istringstream stream(first_line);

    std::string method, path, version;
    stream >> method >> path >> version;

    std::cout << "New request detected: " << method << " " << path << " " << version << "\n";
    const std::string response = Routes::make_server_response(path);

    write(client, response.data(), response.size());
    close(client);
}
