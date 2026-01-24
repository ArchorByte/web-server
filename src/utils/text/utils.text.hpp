#ifndef UTILS_TEXT_HPP
#define UTILS_TEXT_HPP

#include <string>

namespace Text
{
    ////////////////////////
    ///// integers.cpp /////
    ////////////////////////

    bool is_an_integer
    (
        const std::string &input
    );

    ////////////////////
    ///// trim.cpp /////
    ////////////////////

    std::string trim
    (
        const std::string &input
    );
}

#endif
