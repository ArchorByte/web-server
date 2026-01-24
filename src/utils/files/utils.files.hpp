#ifndef UTILS_FILES_HPP
#define UTILS_FILES_HPP

#include <string>
#include <vector>

namespace Files
{
    ////////////////////////////
    ///// files.reader.cpp /////
    ////////////////////////////

    std::vector<std::string> read_file
    (
        const std::string &file_path
    );

    std::vector<char> read_binary_file
    (
        const std::string &file_path
    );
}

#endif
