//
// Created by Michael Lewis on 4/12/23.
//

#ifndef EXCHANGEMATCHINGENGINE_USERPROXYENGINE_HPP
#define EXCHANGEMATCHINGENGINE_USERPROXYENGINE_HPP

#include <string>
#include <vector>

#include "../Common/Servers/Server.hpp"

class UserProxyEngine
{
private:
    std::vector<std::string> orderBook;
    Server* server;
    bool exchangeOpen;

    // Avoids unintentional or intentional copies and clones of the Exchange
    UserProxyEngine(const UserProxyEngine&);
    UserProxyEngine& operator=(const UserProxyEngine&);

    void startEngine() const;
    static void printMenu();
    static int listenForRequest();
    static void printHelp();
    static void printMarketStats();
    static void submitOffer();
    static void submitBid();
    static void printWallet();
    static void goToNextTimeframe();
    static bool validateRequest(int request);
    static void onSubmitRequest(int request);

public:
    UserProxyEngine(std::vector<std::string>& orderBook, Server* server);
    ~UserProxyEngine() = default;
};


#endif //EXCHANGEMATCHINGENGINE_USERPROXYENGINE_HPP
