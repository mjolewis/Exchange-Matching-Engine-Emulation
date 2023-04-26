//
// Created by Michael Lewis on 4/12/23.
//

#include <iostream>

#include "UserProxyServer.hpp"
#include "UserProxyEngine.hpp"
#include "../Common/Utils/CsvReader.hpp"

void UserProxyServer::initializeExchange()
{
    loadOrderBook();
    printOrderBook();
    UserProxyEngine engine{this->orderBook, this};
}

void UserProxyServer::loadOrderBook()
{
    this->orderBook = CsvReader::readCsv("../20200317.csv");
}

void UserProxyServer::printOrderBook()
{
    std::cout << "Printing Order Book" << std::endl;
}
