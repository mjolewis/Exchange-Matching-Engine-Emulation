//
// Created by Michael Lewis on 4/12/23.
//

#include "iostream"
#include "UserProxyEngine.hpp"
#include "ExchangeOptions.hpp"

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
            std::cout << "You're goal is to make money. Analyze the bids and offers." << std::endl;
            break;
        case 2:
            std::cout << "Stats placeholder" << std::endl;
            break;
        case 3:
            std::cout << "Make an offer" << std::endl;
            break;
        case 4:
            std::cout << "Make a bid" << std::endl;
            break;
        case 5:
            std::cout << "Your wallet is empty" << std::endl;
            break;
        case 6:
            std::cout << "Going to next timeframe" << std::endl;
            break;
        default:
            isValidRequest = false;
            std::cout << "Invalid request" << std::endl;
    }

    return isValidRequest;
}

void UserProxyEngine::onSubmitRequest(int request)
{

}