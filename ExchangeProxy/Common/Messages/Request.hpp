//
// Created by Michael Lewis on 4/16/23.
//

#ifndef EXCHANGEMATCHINGENGINE_REQUEST_HPP
#define EXCHANGEMATCHINGENGINE_REQUEST_HPP

// Required standard lib dependencies
#include <chrono>    // System clock etc.: http://en.cppreference.com/w/cpp/chrono
#include <iomanip>   // std::put_time, to convert timestamp to string: http://en.cppreference.com/w/cpp/header/iomanip

#include "Side.hpp"

// Encapsulate all the necessary data for a request for intuitive structuring of the parameters
struct RequestData
{
    std::string id;
    double price;
    double quantity;
    Side side;
    std::string symbol;
    std::chrono::steady_clock::time_point timestamp;
};

/**
 * Acts as an interface for trade request data and implements common functionality for derived classes.
 * Importantly, Requests should never be copied, so the ctor and operator= are private. Moreover, only a
 * derived class should have access to the underlying data members.
 */
class Request
{
public:
    Request();
    virtual ~Request();

public:

    // Accessors
    virtual std::string getId();
    virtual double getPrice();
    virtual double getQuantity();
    virtual Side getSide();
    virtual std::string getSymbol();
    virtual std::string getTimestamp();

    // Mutators for replace requests


protected:
    RequestData* requestData;
    std::map<long, Request> openOrdersById;
    std::map<long, Request> closedOrdersById;

private:
    Request(const Request&);
    Request& operator=(const Request&);
};

/**
 * Provides an interface for algo orders. This will be used for the demo purposes when the orders are read in
 * from the historical CSV file.
 */
class AlgoRequest : public Request
{
public:
    AlgoRequest(double price, double quantity, const Side& side, const std::string& symbol);
    ~AlgoRequest() override;

private:
    // Prevent copies from being made of this request
    AlgoRequest(const AlgoRequest&);
    AlgoRequest operator=(const AlgoRequest&);
};

#endif //EXCHANGEMATCHINGENGINE_REQUEST_HPP
