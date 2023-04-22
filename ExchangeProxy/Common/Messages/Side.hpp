//
// Created by Michael Lewis on 4/16/23.
//

#ifndef EXCHANGEMATCHINGENGINE_SIDE_HPP
#define EXCHANGEMATCHINGENGINE_SIDE_HPP

#include <string>
#include "../DataStructures/AbstractCodes.hpp"

/**
 * Encapsulate the necessary data to represent the side of an order.
 */
class Side : public AbstractCodes
{
private:
    Side(int id, std::string desc) : AbstractCodes(id, std::move(desc)) {}

public:
    Side() = default;
    // Enum declarations
    static const Side BID;
    static const Side OFFER;

    static const std::map<int, AbstractCodes> CODES_BY_ID;
};

// Enum definitions
const Side Side::BID = Side{1, "Bid"};
const Side Side::OFFER = Side{2, "Offer"};


#endif //EXCHANGEMATCHINGENGINE_SIDE_HPP
