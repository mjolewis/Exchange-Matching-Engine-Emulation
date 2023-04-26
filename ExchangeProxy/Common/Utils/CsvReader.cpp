//
// Created by Michael Lewis on 4/23/23.
//

#include <fstream>
#include <string>
#include <vector>

#include "CsvReader.hpp"

/**
 * Opens a csv file and reads its content line by line
 * @param filename
 * @return
 */
std::vector<Request*> CsvReader::readCsv(const std::string& filename)
{
    std::ifstream csvFile{filename};
    std::string line;
    std::vector<Request*> requests;

    if (csvFile.is_open())
    {
        while (std::getline(csvFile, line))
        {
            std::vector<std::string> tokens = tokenize(line, ',');
            try
            {
                requests.push_back(convertStringToRequest(tokens));
            }
            catch (const std::exception& e)
            {
                // silent
            }
        }

        // Close resource to prevent memory leaks
        csvFile.close();
    }

    return requests;
}

std::vector<std::string> CsvReader::tokenize(const std::string& line, char separator)
{
    signed int start;
    signed int end;
    std::string token;
    std::vector<std::string> tokens;

    start = (signed int) line.find_first_not_of(separator, 0);

    do
    {
        end = (signed int) line.find_first_of(separator, start);
        if (start == line.length() || start == end) break;
        if (end >= 0) token = line.substr(start, end - start);
        else token = line.substr(start, line.length() - start);
        tokens.push_back(token);
        start = end + 1;
    } while (end != std::string::npos);

    return tokens;
}

Request* CsvReader::convertStringToRequest(const std::vector<std::string>& tokens)
{
    if (tokens.size() != 5)
    {
        throw std::exception{};
    }

    double price;
    double size;
    Side side;
    std::string symbol;
    try
    {
        price = std::stod(tokens.at(3));
        size = std::stod(tokens.at(4));
        side = Side::getSideFromString(tokens.at(2));
        symbol = tokens.at(1);
    }
    catch(const std::exception& e)
    {
        throw e;
    }

    return new ManualRequest{price, size, side, symbol};
}
