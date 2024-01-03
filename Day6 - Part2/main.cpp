#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

class Race
{
public:
    long long int time{0};
    long long int distance{0};
    long long int speed{0};
    long long int remain{0};
    long long int score{0};
    long long int poss{0};

    Race() = default;
    Race(long long int timeParam, long long int distanceParam)
    {
        time = timeParam;
        distance = distanceParam;
    }

    long long int calculate(){
        speed = 0;
        remain = 0;
        score = 0;

        for(long long int i{0}; i <= time; i++){
            remain = time - i;
            speed = i;
            score = speed * remain;
            if(score > distance){
                ++poss;
                //std::cout << "speed : " << speed << " remain : " << remain << " score : " << score << " distance : " << distance << std::endl;
            }
        }
        //std::cout << poss << std::endl;

        return poss;
    }

};

int main()
{   
    std::ifstream fin("race.txt");
    if (!fin) {
        std::cerr << "problem failed to open" << std::endl;
        return 1;
    }

    std::vector<std::string> data;
    std::string line;
    long long int timey{};
    long long int distancey{};


    // Read lines from the file
    while (std::getline(fin, line)) {
        // Remove whitespace from each line
        line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
        data.push_back(line);
    }
    std::string str1 = data[0].substr(5, data[0].length());
    std::string str2 = data[1].substr(9, data[1].length());

    std::istringstream(str1) >> timey;
    std::istringstream(str2) >> distancey;



    Race r1(timey, distancey);

    long long int total{0};
    total = r1.calculate();

    std::cout << total << std::endl;

    return 0;
}