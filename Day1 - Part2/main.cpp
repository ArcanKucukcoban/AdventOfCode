#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>

int main() {
    int sum = 0;
    std::unordered_map<std::string, int> digits = {
        {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5},
        {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}, {"ten", 10}
    };

    for (int i = 0; i < 10; ++i) {
        digits[std::to_string(i)] = i;
    }

    std::ifstream file("clue1.txt");
    if (!file) {
        std::cerr << "Failed to open input file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<int> lineDigits;
        for (size_t i = 0; i < line.length(); ++i) {
            for (const auto& digit : digits) {
                if (line.substr(i).find(digit.first) == 0) {
                    lineDigits.push_back(digit.second);
                    break;
                }
            }
        }
        sum += lineDigits.front() * 10 + lineDigits.back();
    }

    std::cout << sum << std::endl;

    return 0;
}