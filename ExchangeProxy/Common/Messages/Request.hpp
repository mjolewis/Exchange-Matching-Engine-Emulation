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
    std::chrono::steady_clock::time_point timestamp;
    std::string id;
    double price;
    double quantity;
    Side side;
    std::string symbol;
};

/**
 * Acts as an interface for trade request data and implements common functionality for derived classes.
 * Importantly, Requests should never be copied, so the ctor and operator= are private. Moreover, only a
 * derived class should have access to the underlying data members.
 */
class Request
{
private:
    // Prevent unintentional or intentional copies and clones of this request
    Request(const Request&);
    Request& operator=(const Request&);

protected:
    RequestData* requestData;
    std::map<long, Request> openOrdersById;
    std::map<long, Request> closedOrdersById;

public:
    Request();
    virtual ~Request();

    // Accessors
    virtual std::string getTimestamp();
    virtual std::string getId();
    virtual double getPrice();
    virtual double getQuantity();
    virtual const Side& getSide();
    virtual std::string getSymbol();
    virtual const std::map<long, Request>& getOpenOrdersById();
    virtual const std::map<long, Request>& getClosedOrdersById();

    // Mutators for replace requests
};

/**
 * Provides an interface for algo orders. This will be used for demoing asynchronous requests generated
 * by multiple trader threads to simulate algorithmic flow.
 */
class AlgoRequest : public Request
{
private:
    // Prevent unintentional or intentional copies and clones of this request
    AlgoRequest(const AlgoRequest&);
    AlgoRequest operator=(const AlgoRequest&);

public:
    AlgoRequest(double price, double quantity, const Side& side, const std::string& symbol);
    ~AlgoRequest() override;
};

/**
 * Provides an interface for algo orders. This will be used for demoing manual order flow where traders
 * enter their requests via a command line interface.
 */
class ManualRequest : public Request
{
private:
    // Prevent unintentional or intentional copies and clones of this request
    ManualRequest(const ManualRequest&);
    ManualRequest& operator=(const ManualRequest&);

public:
    ManualRequest(double price, double quantity, const Side& side, const std::string& symbol);
    ~ManualRequest() override;
};

#endif //EXCHANGEMATCHINGENGINE_REQUEST_HPP
