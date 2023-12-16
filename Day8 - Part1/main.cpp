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
    std::string loop = "LRLRLRRLRRLRLRRRLRRLRLRRLLLRRRLRRRLLRRLRRRLRRRLRRLRRLRRRLRRLRLRLRRRLRRLRRLLRRRLLRLRRRLRRRLRRLRRRLRRLLRLLRRRLRRLRLRRRLRLRLRRRLLRLRRLLRRRLRRRLRLRRLLRRLRLRRLRRRLRLLRRRLRRRLLRLLRLLRRRLRLRLRLRLRRLRRLRLRRRLLLRLLRRRLRRLLRLRLRRRLLRLRRRLLRRLRRLRLRLRLRRLRRLRRRLRRRLRRLRRLRRRLRLRRRLRLRRRR";

    std::ifstream fin("race.txt");
    std::vector<std::string> data;
    std::string line;

    while(std::getline(fin, line)){
        data.push_back(line);
    }

    for(int i{0}; i < loop.length(); ++i){
        std::cout << i << std::endl;
    }

    return 0;
}