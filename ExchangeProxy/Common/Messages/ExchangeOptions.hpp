//
// Created by Michael Lewis on 4/12/23.
//

#ifndef EXCHANGEMATCHINGENGINE_EXCHANGEOPTIONS_HPP
#define EXCHANGEMATCHINGENGINE_EXCHANGEOPTIONS_HPP

#include "string"
#include "map"
#include "vector"
#include "../DataStructures/AbstractCodes.hpp"

class ExchangeOptions : public AbstractCodes
{
private:
    ExchangeOptions(int id, std::string desc) : AbstractCodes(id, std::move(desc)) {}

public:

    // Enum declarations
    static const ExchangeOptions HELP;
    static const ExchangeOptions PRINT_STATS;
    static const ExchangeOptions OFFER;
    static const ExchangeOptions BID;
    static const ExchangeOptions WALLET;
    static const ExchangeOptions CONTINUE;

    static const std::map<int, AbstractCodes> CODES_BY_ID;

    // Functions
    static const std::vector<AbstractCodes>* getAllOptions();
    static AbstractCodes getCodesById(int id);
};

// Enum definitions
const ExchangeOptions ExchangeOptions::HELP = ExchangeOptions(1, "1. Print help");
const ExchangeOptions ExchangeOptions::PRINT_STATS = ExchangeOptions(2, "2. Print exchange stats");
const ExchangeOptions ExchangeOptions::OFFER = ExchangeOptions(3, "3. Make an offer");
const ExchangeOptions ExchangeOptions::BID = ExchangeOptions(4, "4. Make a bid");
const ExchangeOptions ExchangeOptions::WALLET = ExchangeOptions(5, "5. Print wallet");
const ExchangeOptions ExchangeOptions::CONTINUE = ExchangeOptions(6, "6. Continue");

// Functions
const std::map<int, AbstractCodes> ExchangeOptions::CODES_BY_ID =
        {
            std::pair<int, AbstractCodes>(ExchangeOptions::HELP.operator int(), ExchangeOptions::HELP),
            std::pair<int, AbstractCodes>(ExchangeOptions::PRINT_STATS.operator int(), ExchangeOptions::PRINT_STATS),
            std::pair<int, AbstractCodes>(ExchangeOptions::OFFER.operator int(), ExchangeOptions::OFFER),
            std::pair<int, AbstractCodes>(ExchangeOptions::BID.operator int(), ExchangeOptions::BID),
            std::pair<int, AbstractCodes>(ExchangeOptions::WALLET.operator int(), ExchangeOptions::WALLET),
            std::pair<int, AbstractCodes>(ExchangeOptions::CONTINUE.operator int(), ExchangeOptions::CONTINUE)
        };

const std::vector<AbstractCodes> *ExchangeOptions::getAllOptions()
{
    auto* allOptions = new std::vector<AbstractCodes>();
    for (const auto& option : CODES_BY_ID)
    {
        allOptions->push_back(option.second);
    }
    return allOptions;
}

AbstractCodes ExchangeOptions::getCodesById(int id)
{
    return CODES_BY_ID.at(id);
}

#endif //EXCHANGEMATCHINGENGINE_EXCHANGEOPTIONS_HPP
