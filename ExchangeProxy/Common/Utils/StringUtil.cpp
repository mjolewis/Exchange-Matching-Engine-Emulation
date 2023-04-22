//
// Created by Michael Lewis on 4/22/23.
//

#include "StringUtil.hpp"

#include <string>
#include <vector>

/**
 * Tokenizes and caches the elements of an input string.
 * @param input The string to be tokenized
 * @param separator The token separator
 * @return A std::vector<std::string> of tokens
 */
std::vector<std::string> StringUtil::getVectorFromDelimitedString(std::string &input, char separator)
{
    std::vector<std::string> tokens;
    std::string token;
    auto start = (signed int) input.find_first_not_of(separator, 0);
    signed int end;

    do
    {
        // End of a single token is identified by the occurrence of a separator
        end = (signed int) input.find_first_of(separator, start);

        if (start == input.length() || start == end) break;

        if (end >= 0) token = input.substr(start, end - start);
        else token = input.substr(start, input.length());
        start = end + 1;

        tokens.push_back(token);
    } while (end != std::string::npos);

    return tokens;
}
