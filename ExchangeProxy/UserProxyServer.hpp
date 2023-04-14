//
// Created by Michael Lewis on 4/12/23.
//

#ifndef EXCHANGEMATCHINGENGINE_USERPROXYSERVER_HPP
#define EXCHANGEMATCHINGENGINE_USERPROXYSERVER_HPP

#include "UserProxyEngine.hpp"

class UserProxyServer
{
public:
    UserProxyServer();

private:
    static void loadOrderData();
    static UserProxyEngine* createEngine();
};


#endif //EXCHANGEMATCHINGENGINE_USERPROXYSERVER_HPP
