#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>

int main() {
    std::ifstream fin("clue1.txt");
    std::vector<std::string> data;
    std::string line;
    int total = 0;

    while (std::getline(fin, line)) {
        data.push_back(line);
    }

    for (int i = 0; i < data.size(); ++i) {
        std::string temp = data[i];
        std::string fChar(1, temp[temp.find_first_of("0123456789")]);
        std::string lChar(1, temp[temp.find_last_of("0123456789")]);
        int first = fChar[0] - '0';
        int last = lChar[0] - '0';
        std::cout << first << last << std::endl;
        int result = first * 10 + last;
        total += result;
    }

    std::cout << total << std::endl;

    return 0;
}