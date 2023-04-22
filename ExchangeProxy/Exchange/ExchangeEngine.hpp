//
// Created by Michael Lewis on 4/21/23.
//

#ifndef EXCHANGEMATCHINGENGINE_EXCHANGEENGINE_HPP
#define EXCHANGEMATCHINGENGINE_EXCHANGEENGINE_HPP

#include <string>
#include <vector>

#include "../Common/Servers/Server.hpp"

/**
 * This class encapsulates a naive version of an exchange.
 * Clients of the exchange can submit requests and the exchange's matching engine will handle
 * and execute those trades which are possible based on the state of the order book.
 * To facilitate the matching, the matching engine will continually run in the background until
 * the end of the trading day. All remaining and eligible trades (e.g. GTC, GTD) will be persisted
 * and reloaded into the matching engine the following day until they are either executed or otherwise
 * cancelled or expired (For now, this demo app simply discards them).
 *
 * The Exchange is also capable of handling requests from multiple brokers (threads in this demo app)
 * who might submit requests at the same time. Thus, we make use of STLs mutual exclusion and condition
 * variables.
 */
class ExchangeEngine
{
private:
    std::vector<std::string> orderBook;
    Server* server;
    bool exchangeOpen;

    // Avoids unintentional or intentional copies and clones of the Engine
    ExchangeEngine(const ExchangeEngine&);
    ExchangeEngine& operator=(const ExchangeEngine&);

    void startEngine();
    void stopEngine();

public:
    ExchangeEngine(std::vector<std::string>& orderBook, Server* server);
    ~ExchangeEngine() = default;
};


#endif //EXCHANGEMATCHINGENGINE_EXCHANGEENGINE_HPP
