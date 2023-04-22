//
// Created by Michael Lewis on 4/21/23.
//

#include <string>
#include <vector>

#include "ExchangeEngine.hpp"

ExchangeEngine::ExchangeEngine(ExchangeServer* server, std::vector<std::string>& orderBook) : server(server), orderBook(orderBook)
{

    this->exchangeOpen = true;
    startEngine();
}

/* Launches the matching engine in a dedicated thread. This enables asynchronous handling of trader/broker
 * requests at all times. It can also be expanded to read from a configuration file to determine how many
 * threads should be created.
*/
void ExchangeEngine::startEngine()
{

}