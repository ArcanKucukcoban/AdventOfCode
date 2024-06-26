/*


 NOT SOLVED



*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>

/*
class Cards
{
public:
    std::vector<int> winVec1{};
    std::vector<int> playVec2{};
    int exMatch{};
    std::vector<std::string> dat;
    int ii{};
    Cards() = default;
    Cards(std::vector<int> a, std::vector<int> b, int c, std::vector<std::string> exDat, int exii)
    {
        winVec1 = a;
        playVec2 = b;
        exMatch = c;
        dat = exDat;
        ii = exii;
    }
    
};
*/

int main()
{
    std::fstream fin("scratchcards.txt");
    std::vector<std::string> data;
    std::string line;
    int total{0};
    int newTotal{0};
    std::string card[210];
    std::string winning[10]{};
    std::string played[25]{};
    std::vector<std::string> newData;

    while (std::getline(fin, line))
    {
        data.push_back(line);
    }

    for (int i{}; i < data.size(); ++i)
    {
        size_t colonPos = data[i].find(':');
        size_t tokenPos = data[i].find('|');
        if (colonPos != std::string::npos)
        {
            card[i] = data[i].substr(0, colonPos);
            winning[i] = data[i].substr(colonPos + 1, tokenPos - colonPos - 1);
            played[i] = data[i].substr(tokenPos + 1, data[i].length());
            // std::cout << "card[" << i << "] : " << card[i] << std::endl;
            // std::cout << "winning[" << i << "] : " << winning[i] << std::endl;
            // std::cout << "played[" << i << "] : " << played[i] << std::endl;

            // Convert winning[i] to integer groups
            std::vector<int> winningInts;
            std::string group;
            for (char c : winning[i])
            {
                if (std::isdigit(c))
                {
                    group += c;
                }
                else if (!group.empty())
                {
                    winningInts.push_back(std::stoi(group));
                    group.clear();
                }
            }
            if (!group.empty())
            {
                winningInts.push_back(std::stoi(group));
            }

            // Convert played[i] to integer groups
            std::vector<int> playedInts;
            std::string group1;
            for (char c : played[i])
            {
                if (std::isdigit(c))
                {
                    group1 += c;
                }
                else if (!group1.empty())
                {
                    playedInts.push_back(std::stoi(group1));
                    group1.clear();
                }
            }
            if (!group1.empty())
            {
                playedInts.push_back(std::stoi(group1));
            }

            int match{0};
            for (int m{}; m < 10; ++m)
            {
                for (int n{}; n < 25; ++n)
                {
                    if (winningInts[m] == playedInts[n])
                    {
                        // std::cout << "cardNo : " << i << " winningInts[" << m << "] : " <<  winningInts[m] << " playedInts[" << n << "] : " << playedInts[n] << std::endl;
                        ++match;
                    }
                }
            }

            // std::cout << "i : " << i << "Match : " <<  match << std::endl;
            if (match > 0)
            {
                double result = std::pow(2, (match - 1));
                total += result;
            }
        }
    }

    return 0;
}