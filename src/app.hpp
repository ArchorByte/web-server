#ifndef APP_HPP
#define APP_HPP

#include "routes/routes.hpp"
#include "socket/socket.hpp"
#include "utils/utils.hpp"

namespace App
{
    /////////////////////////////
    ///// routes/routes.hpp /////
    /////////////////////////////

    namespace Routes = ::Routes;

    /////////////////////////////
    ///// socket/socket.hpp /////
    /////////////////////////////

    namespace Socket = ::Socket;

    ///////////////////////////////
    ///// utils/app.utils.hpp /////
    ///////////////////////////////

    namespace Utils = ::Utils;
}

#endif
