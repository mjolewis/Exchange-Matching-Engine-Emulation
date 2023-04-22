//
// Created by Michael Lewis on 4/20/23.
//

#include <iostream>
#include <vector>
#include "ExchangeServer.hpp"
#include "ExchangeEngine.hpp"

void ExchangeServer::initializeExchange()
{
    loadOrderBook();
    printOrderBook();
    ExchangeEngine engine{this, this->orderBook};
}

// Will eventually load GoodTill orders. For now, simply loads orders from a csv
void ExchangeServer::loadOrderBook()
{
    //todo
}

void ExchangeServer::printOrderBook()
{
    std::cout << "*** Order Book ***\n\n" << std::endl;
    for (std::string& order : this->orderBook)
    {
        std::cout << order << std::endl;
    }
    std::cout << "*** End Order Book***\n\n" << std::endl;
}