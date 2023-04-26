//
// Created by Michael Lewis on 4/26/23.
//

#include "Side.hpp"

bool Side::operator==(const Side* thatSide) const
{
    return this == thatSide;
}

Side Side::getSideFromString(const std::string& side)
{
    if (side == Side::BID.getDesc() || side == "BUY" || side == "bid") return Side::BID;
    if (side == Side::OFFER.getDesc() || side == "ASK" || side == "ask") return Side::OFFER;
    else return Side::UNKNOWN;
}