//
// Created by Michael Lewis on 4/20/23.
//

#ifndef EXCHANGEMATCHINGENGINE_EXCHANGESERVER_HPP
#define EXCHANGEMATCHINGENGINE_EXCHANGESERVER_HPP

#include <string>
#include <vector>

/**
 * This class encapsulates a naive server in which the ExchangeEngine will run.
 * This protocol of the server will eventually expand to include the following:
 *
 * Multiple threads for the engine.
 *
 * All remaining and eligible trades (e.g. GTC, GTD) will be persisted and reloaded into the
 * matching engine the following day until they are either executed or otherwise
 * cancelled or expired (For now, this demo app simply discards them).
 *
 * Enabling resiliency by registering heartbeats for other apps in the system. Including heartsbeats of
 * other ExchangeServers that run in passive mode in the event a failover is required.
 */
class ExchangeServer
{
private:
    std::vector<std::string> orderBook;

    // Avoid unintentional or intentional copies and clones of the Exchange
    ExchangeServer(const ExchangeServer&);
    ExchangeServer& operator=(const ExchangeServer&);

    void loadOrderBook();
    void printOrderBook();

public:
    ExchangeServer() = default;
    ~ExchangeServer() = default;

    void initializeExchange();
};

#endif //EXCHANGEMATCHINGENGINE_EXCHANGESERVER_HPP
