#include <iostream>
#include <string>
#include <vector>

class Race
{
public:
    double time{0};
    double distance{0};
    double speed{0};
    double remain{0};
    double score{0};
    int poss{0};

    Race() = default;
    Race(double timeParam, double distanceParam)
    {
        time = timeParam;
        distance = distanceParam;
    }

    double calculate(){
        speed = 0;
        remain = 0;
        score = 0;

        for(int i{0}; i <= time; i++){
            remain = time - i;
            speed = i;
            score = speed * remain;
            if(score > distance){
                ++poss;
                //std::cout << "speed : " << speed << " remain : " << remain << " score : " << score << " distance : " << distance << std::endl;
            }
        }
        std::cout << poss << std::endl;

        return poss;
    }

};

int main()
{

    Race r1(48, 390);
    Race r2(98, 1103);
    Race r3(90, 1112);
    Race r4(83, 1360);

    r1.calculate();
    r2.calculate();
    r3.calculate();
    r4.calculate();

    int total{0};
    
    total = 27 * 73 * 61 * 38;
    std::cout << total << std::endl;

    return 0;
}