//
// Created by Michael Lewis on 4/22/23.
//

#ifndef EXCHANGEMATCHINGENGINE_SERVER_HPP
#define EXCHANGEMATCHINGENGINE_SERVER_HPP

class Server
{
public:

    virtual void loadOrderBook() = 0;
    virtual void printOrderBook() = 0;
    virtual void initializeExchange() = 0;
};

#endif //EXCHANGEMATCHINGENGINE_SERVER_HPP
