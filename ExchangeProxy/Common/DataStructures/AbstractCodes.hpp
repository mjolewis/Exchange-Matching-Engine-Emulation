//
// Created by Michael Lewis on 4/12/23.
//

#ifndef EXCHANGEMATCHINGENGINE_ABSTRACTCODES_HPP
#define EXCHANGEMATCHINGENGINE_ABSTRACTCODES_HPP

#include "string"
#include "map"

class AbstractCodes
{
private:
    int id{};
    std::string desc;

protected:
    AbstractCodes(int id, std::string desc)
    {
        this->id = id;
        this->desc = std::move(desc);
    }

public:
    AbstractCodes() = default;

    virtual ~AbstractCodes() = default;

    inline virtual std::string getDesc() const {return this->desc;}

    inline virtual constexpr explicit operator int() const {return id;}
};

#endif //EXCHANGEMATCHINGENGINE_ABSTRACTCODES_HPP
