// Multiple inclusion guards to avoid linker errors
// Prevents re-compilationsIn if this file is included in multiple source files
#ifndef EXCHANGEMATCHINGENGINE_USERPROXYSERVER_CPP
#define EXCHANGEMATCHINGENGINE_USERPROXYSERVER_CPP

#include <iostream>
#include "UserProxy/UserProxyServer.hpp"

int main()
{
    while (true)
    {
        new UserProxyServer;
    }
    return 0;
}

#endif // EXCHANGEMATCHINGENGINE_USERPROXYSERVER_CPP