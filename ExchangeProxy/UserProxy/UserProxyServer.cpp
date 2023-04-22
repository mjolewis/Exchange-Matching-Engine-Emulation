//
// Created by Michael Lewis on 4/12/23.
//

#include "UserProxyServer.hpp"
#include "UserProxyEngine.hpp"

void UserProxyServer::initializeExchange()
{
    loadOrderBook();
    printOrderBook();
    UserProxyEngine engine{this->orderBook, this};
}

void UserProxyServer::loadOrderBook()
{

}

void UserProxyServer::printOrderBook()
{

}
