//
// Created by Michael Lewis on 4/12/23.
//

#include "UserProxyServer.hpp"

UserProxyServer::UserProxyServer()
{
    loadOrderData();
    createEngine();
}

void UserProxyServer::loadOrderData()
{

}

UserProxyEngine* UserProxyServer::createEngine()
{
   return new UserProxyEngine;
}
