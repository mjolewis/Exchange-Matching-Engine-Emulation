//
// Created by Michael Lewis on 4/12/23.
//

#ifndef EXCHANGEMATCHINGENGINE_USERPROXYENGINE_HPP
#define EXCHANGEMATCHINGENGINE_USERPROXYENGINE_HPP


class UserProxyEngine
{
public:
    // Default constructor opens the exchange and launches the matching engine. There is heap allocation
    // to accommodate variable number of coins due to new Initial Coin Offerings
    UserProxyEngine();

private:
    static void initializeExchange();
    static int listenForRequest();
    static void onSubmitRequest(int request);
};


#endif //EXCHANGEMATCHINGENGINE_USERPROXYENGINE_HPP
