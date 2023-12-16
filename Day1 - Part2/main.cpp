/*

NOT SOLVED !!!!!!

*/


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <vector>
#include <map>
#include <algorithm>

int main() {
    std::ifstream fin("clue1.txt");
    if (!fin) {
        std::cerr << "Failed to open the input file." << std::endl;
        return 1;
    }

    std::vector<std::string> data;
    std::string line;
    int total = 0;

    std::map<std::string, std::string> replaceMap = {
        {"one", "1"},
        {"two", "2"},
        {"three", "3"},
        {"four", "4"},
        {"five", "5"},
        {"six", "6"},
        {"seven", "7"},
        {"eight", "8"},
        {"nine", "9"}
    };

    while (std::getline(fin, line)) {
        for (const auto& [key, value] : replaceMap) {
            size_t pos = 0;
            while ((pos = line.find(key, pos)) != std::string::npos) {
                line.replace(pos, key.length(), value);
                pos += value.length();
            }
        }
        data.push_back(line);
    }

    for(auto value : data){
        std::cout << value << std::endl;
    }

    for (int i = 0; i < data.size(); ++i) {
        std::string temp = data[i];
        std::string fChar(1, temp[temp.find_first_of("0123456789")]);
        std::string lChar(1, temp[temp.find_last_of("0123456789")]);
        int first = fChar[0] - '0';
        int last = lChar[0] - '0';
        int result = first * 10 + last;
        total += result;
    }

    std::cout << total << std::endl;

    return 0;
}