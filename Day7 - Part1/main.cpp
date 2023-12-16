/*

NOT SOLVED

*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

int main()
{
    std::ifstream fin("race.txt");
    std::vector<std::string> data;
    std::string line;

    // Read input file into a vector of strings
    while (std::getline(fin, line)) {
        data.push_back(line);
    }

    // Split each line into two parts by whitespace
    std::vector<std::pair<std::string, std::string>> splitData; // Vector to store the split data

    for (const std::string& entry : data) {
        std::istringstream iss(entry);
        std::string hands, bids;

        if (iss >> hands >> bids) {
            splitData.push_back(std::make_pair(hands, bids));
        }
    }


    return 0;
}