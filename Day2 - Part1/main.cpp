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

        while (std::getline(partsStream, part, ';')) {
            std::istringstream cubesStream(part);
            std::string cubes;

            // Split cubes into number and color
            while (std::getline(cubesStream, cubes, ',')) {
                std::istringstream cubeStream(cubes);
                int num;
                std::string color;

                cubeStream >> num >> color;

                if ((color == "red" && num > 12) ||
                    (color == "blue" && num > 14) ||
                    (color == "green" && num > 13)) {
                    good = false;
                    break;
                }
            }

            if (!good) {
                break;
            }
        }

        if (good) {
            ans += _id;
        }
    }

    std::cout << ans << std::endl;

    return 0;
}