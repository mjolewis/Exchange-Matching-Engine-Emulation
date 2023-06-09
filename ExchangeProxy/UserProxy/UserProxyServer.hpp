//
// Created by Michael Lewis on 4/12/23.
//

#ifndef EXCHANGEMATCHINGENGINE_USERPROXYSERVER_HPP
#define EXCHANGEMATCHINGENGINE_USERPROXYSERVER_HPP

#include <string>
#include <vector>

#include "../Common/Servers/Server.hpp"
#include "../Common//Messages/Request.hpp"

class UserProxyServer : public Server
{
private:
    std::vector<Request*> orderBook;

    // Avoid unintentional or intentional copies and clones of the Exchange
    UserProxyServer(const UserProxyServer&);
    UserProxyServer& operator=(const UserProxyServer&);

    void loadOrderBook() override;
    void printOrderBook() override;

public:
    UserProxyServer() = default;
    ~UserProxyServer() = default;

    void initializeExchange() override;
};


#endif //EXCHANGEMATCHINGENGINE_USERPROXYSERVER_HPP
