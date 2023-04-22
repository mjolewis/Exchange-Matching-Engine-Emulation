//
// Created by Michael Lewis on 4/22/23.
//

#include <iostream>

#include "UserProxy/UserProxyServer.hpp"

int main()
{
    // Open the Exchange
    std::cout << "*** Exchange is OPEN ***\n\n" << std::endl;
    UserProxyServer NYSE;
    NYSE.initializeExchange();
    return 0;
}