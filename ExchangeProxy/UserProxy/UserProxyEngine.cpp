//
// Created by Michael Lewis on 4/12/23.
//

#include <iostream>

#include "sstream"
#include <vector>

#include "UserProxyEngine.hpp"
#include "../Common/Messages/ExchangeOptions.hpp"

UserProxyEngine::UserProxyEngine(std::vector<Request*>& orderBook, Server* server)
: orderBook(orderBook), server(server)
{
    this->exchangeOpen = true;
    startEngine();
}

void UserProxyEngine::startEngine() const
{
    while (this->exchangeOpen)
    {
        printMenu();
        int request = listenForRequest();
        validateRequest(request);
    }
}

void UserProxyEngine::printMarketStats() const
{
    int bids = 0;
    int offers = 0;

    double bestBid = __DBL_MIN__;
    double bestOffer = __DBL_MAX__;
    for (Request *request : this->orderBook)
    {
        if (&request->getSide() == (Side::BID) || request->getSide().getDesc() == "Bid")
        {
            ++bids;
            if (request->getPrice() > bestBid) bestBid = request->getPrice();
        }
        if (&request->getSide() == (Side::OFFER) || request->getSide().getDesc() == "Offer")
        {
            ++offers;
            if (request->getPrice() < bestOffer) bestOffer = request->getPrice();
        }
    }

    std::cout << "Total Bids=" << bids << ", Best Bid=" << bestBid << "\n"
              << "Total Offers= " << offers << ", Best Offer=" << bestOffer << "\n" << std::endl;
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

bool UserProxyEngine::validateRequest(int request) const
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