//
// Created by Michael Lewis on 4/21/23.
//

#include <string>
#include <vector>

#include "ExchangeEngine.hpp"

ExchangeEngine::ExchangeEngine(std::vector<std::string>& orderBook, Server* server)
: orderBook(orderBook), server(server)
{

    this->exchangeOpen = true;
    startEngine();
}

/*
 * Launches the matching engine in a dedicated thread. This enables asynchronous handling of trader/broker
 * requests at all times. It can also be expanded to read from a configuration file to determine how many
 * threads should be created.
*/
void ExchangeEngine::startEngine()
{

}

/*
 * Stops the matching engines at the end of the trading day. This will need to gracefully shutdown all
 * associated engine threads and eventually persist all eligible good till orders remaining in the order book.
 */
void ExchangeEngine::stopEngine()
{

}