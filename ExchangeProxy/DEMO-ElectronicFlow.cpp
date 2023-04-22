// Multiple inclusion guards to avoid linker errors
// Prevents re-compilationsIn if this file is included in multiple source files
#ifndef EXCHANGEMATCHINGENGINE_USERPROXYSERVER_CPP
#define EXCHANGEMATCHINGENGINE_USERPROXYSERVER_CPP

#include <iostream>
#include "Exchange/ExchangeServer.hpp"

int main()
{
    // Open the Exchange
    std::cout << "*** Exchange is OPEN ***\n\n" << std::endl;
    ExchangeServer NYSE;
    NYSE.initializeExchange();
    return 0;
}

#endif // EXCHANGEMATCHINGENGINE_USERPROXYSERVER_CPP