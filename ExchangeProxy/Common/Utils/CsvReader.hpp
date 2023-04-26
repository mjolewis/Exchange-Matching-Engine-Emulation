//
// Created by Michael Lewis on 4/23/23.
//

#ifndef EXCHANGEMATCHINGENGINE_CSVREADER_HPP
#define EXCHANGEMATCHINGENGINE_CSVREADER_HPP

#include <string>
#include <vector>

#include "../Messages/Request.hpp"

class CsvReader
{
private:
    CsvReader() = default;
    ~CsvReader() = default;

    static std::vector<std::string> tokenize(const std::string& line, char separator);
    static Request* convertStringToRequest(const std::vector<std::string>& tokens);

public:
    static std::vector<Request*> readCsv(const std::string& fileName);
};


#endif //EXCHANGEMATCHINGENGINE_CSVREADER_HPP
