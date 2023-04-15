//
// Created by Michael Lewis on 4/12/23.
//

#include "iostream"
#include "UserProxyEngine.hpp"
#include "../Common/Messages/ExchangeOptions.hpp"

UserProxyEngine::UserProxyEngine()
{
    initializeExchange();
}

void UserProxyEngine::initializeExchange()
{
    printMenu();
    int request = listenForRequest();
    bool isValidRequest = validateRequest(request);
    if (isValidRequest) onSubmitRequest(request);
}

void UserProxyEngine::printMenu()
{
    const std::vector<AbstractCodes>* options = ExchangeOptions::getAllOptions();
    std::cout << "============\n\n" << std::endl;
    for (const AbstractCodes& option : *options)
    {
        std::cout << option.getDesc() << std::endl;
    }
    std::cout << "============" << std::endl;
}

int UserProxyEngine::listenForRequest()
{
    int request;
    std::cin >> request;
    std::cout << "You selected " << request << std::endl;
    return request;
}

bool UserProxyEngine::validateRequest(int request)
{
    bool isValidRequest = true;
    switch (request)
    {
        case 1:
            UserProxyEngine::printHelp();
            break;
        case 2:
            UserProxyEngine::printMarketStats();
            break;
        case 3:
            UserProxyEngine::submitOffer();
            break;
        case 4:
            UserProxyEngine::submitBid();
            break;
        case 5:
            UserProxyEngine::printWallet();
            break;
        case 6:
            UserProxyEngine::goToNextTimeframe();
            break;
        default:
            isValidRequest = false;
            std::cout << "Invalid request" << std::endl;
    }

    return isValidRequest;
}

void UserProxyEngine::printHelp()
{
    std::cout << "You're goal is to make money. Analyze the bids and offers." << std::endl;
}

void UserProxyEngine::printMarketStats()
{
    std::cout << "Stats placeholder" << std::endl;
}

void UserProxyEngine::submitOffer()
{
    std::cout << "Make an offer" << std::endl;
}

void UserProxyEngine::submitBid()
{
    std::cout << "Make a bid" << std::endl;
}

void UserProxyEngine::printWallet()
{
    std::cout << "Your wallet is empty" << std::endl;
}

void UserProxyEngine::goToNextTimeframe()
{
    std::cout << "Going to next timeframe" << std::endl;
}

void UserProxyEngine::onSubmitRequest(int request)
{

}