/*

NOT SOLVED

*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>

int main() {
    std::ifstream fin("seeds.txt");
    std::vector<std::string> data;
    std::string line;
    

    while (std::getline(fin, line)) {
        data.push_back(line);
    }


    return 0;
}