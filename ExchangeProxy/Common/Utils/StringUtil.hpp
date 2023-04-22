//
// Created by Michael Lewis on 4/22/23.
//

#ifndef EXCHANGEMATCHINGENGINE_STRINGUTIL_HPP
#define EXCHANGEMATCHINGENGINE_STRINGUTIL_HPP

#include <string>
#include <vector>

/**
 * Utility functions for string operations.
 */
class StringUtil
{
private:
    StringUtil()=default;
    ~StringUtil()=default;

public:
    static std::vector<std::string> getVectorFromDelimitedString(std::string& input, char separator);
};


#endif //EXCHANGEMATCHINGENGINE_STRINGUTIL_HPP
