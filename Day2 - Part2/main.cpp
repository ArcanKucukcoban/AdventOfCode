#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::ifstream fin("gamefile.txt");
    std::vector<std::string> data;
    std::string line;

    // Read input file into a vector of strings
    while (std::getline(fin, line)) {
        data.push_back(line);
    }

    long long int totally{};

    int ans = 0;

    for (const auto& line : data) {
        std::string game, parts;
        std::istringstream iss(line);

        // Split the line into game and parts
        std::getline(iss, game, ':');
        std::getline(iss, parts, ':');

        int _id = std::stoi(game.substr(game.find(' ') + 1));
        bool good = true;

        // Split parts into individual cubes
        std::istringstream partsStream(parts);
        std::string part;
        long long int linePow{};
        int tempR{0};
        int tempG{0};
        int tempB{0};


        while (std::getline(partsStream, part, ';')) {
            std::istringstream cubesStream(part);
            std::string cubes;

            // Split cubes into number and color
            while (std::getline(cubesStream, cubes, ',')) {
                std::istringstream cubeStream(cubes);
                int num;
                std::string color;

                cubeStream >> num >> color;

                if(color == "red" && num > tempR){
                    //std::cout << "id : " << _id << "num : " << num << " tempR : " << tempR << std::endl;
                    tempR = num;
                    //std::cout << "id : " << _id << "num : " << num << " tempR : " << tempR << std::endl;
                } else if(color == "green" && num > tempG){
                    //std::cout << "id : " << _id << "num : " << num << " tempG : " << tempG << std::endl;
                    tempG = num;
                    //std::cout << "id : " << _id << "num : " << num << " tempG : " << tempG << std::endl;
                } else if(color == "blue" && num > tempB){
                    //std::cout << "id : " << _id << "num : " << num << " tempB : " << tempB << std::endl;
                    tempB = num;
                    //std::cout << "id : " << _id << "num : " << num << " tempB : " << tempB << std::endl;
                }
                
            }

            linePow = tempR * tempG * tempB;

        }

        totally += linePow;

    }

    return 0;
}