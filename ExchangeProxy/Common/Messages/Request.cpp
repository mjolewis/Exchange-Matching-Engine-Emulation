//
// Created by Michael Lewis on 4/16/23.
//

#include <chrono>
#include <sstream>
#include <random>
#include "Request.hpp"

Request::Request() : requestData(nullptr) {}

// No heap allocation so use a default constructor
Request::~Request() = default;

std::string Request::getId()
{
    if (Request::requestData == nullptr) return "NULL";
    return Request::requestData->id;
}

double Request::getPrice()
{
    if (Request::requestData == nullptr) return 0;
    return Request::requestData->price;
}

double Request::getQuantity()
{
    if (Request::requestData == nullptr) return 0;
    return Request::requestData->quantity;
}

const Side& Request::getSide()
{
    return Request::requestData->side;
}

std::string Request::getSymbol()
{
    if (Request::requestData == nullptr) return "NULL";
    return Request::requestData->symbol;
}

std::string Request::getTimestamp()
{
    if (Request::requestData == nullptr) return "NULL";
    std::stringstream stream;
    //todo  Convert time stamp to human readable format
//    stream << std::chrono::hh_mm_ss<requestData->timestamp>()>
//    stream << std::put_time(&Request::requestData->timestamp, "%F %T EST");
    return stream.str();
}

const std::map<long, Request>& Request::getOpenOrdersById()
{
    return openOrdersById;
}

const std::map<long, Request>& Request::getClosedOrdersById()
{
    return closedOrdersById;
}

//*** AlgoRequest Implementation ***//

/**
 * Parameterized constructor to instantiate fields of an electronic order
 * @param price The amount the client is willing to offer or bid
 * @param quantity The number of units being traded
 * @param side Bid or Offer depending on if the order represents a buy or a sell
 * @param symbol The instrument identifier
 */
AlgoRequest::AlgoRequest(double price, double quantity, const Side& side, const std::string& symbol)
{
    Request::requestData = new RequestData();

    // Order properties
    Request::requestData->price = price;
    Request::requestData->quantity = quantity;
    Request::requestData->side = side;
    Request::requestData->symbol = symbol;
    Request::requestData->timestamp = std::chrono::high_resolution_clock::now();

    // Generate a random order id based on system clock.
    std::uniform_int_distribution distribution(0,1);
    std::mt19937_64 gen64;
    for (unsigned int i = 0; i < 7; ++i)
    {
        gen64.seed(std::chrono::system_clock::now().time_since_epoch().count());
        requestData->id = std::to_string(distribution(gen64));
    }
}

/**
 * Deallocates the RequestData object from the heap to avoid memory leaks.
 */
AlgoRequest::~AlgoRequest()
{
    delete Request::requestData;
}
