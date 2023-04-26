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
    static const Side UNKNOWN;

    static Side getSideFromString(const std::string& side);
    static const std::map<int, AbstractCodes> CODES_BY_ID;

    bool operator==(const Side* thatSide) const;
};

// Enum definitions
inline const Side Side::BID = Side{1, "Bid"};
inline const Side Side::OFFER = Side{2, "Offer"};
inline const Side Side::UNKNOWN = Side{3, "Unknown"};

#endif //EXCHANGEMATCHINGENGINE_SIDE_HPP
