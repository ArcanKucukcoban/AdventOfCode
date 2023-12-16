/*

NOT SOLVED

*/


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>
#include <algorithm>

class Symbol
{
    public :
        int pos{0};
        std::vector<std::string> dat;
        int i{0};

        char middle{};
        char topleft{};
        char top{};
        char topright{};
        char left{};
        char right{};
        char solustucyan{};
        char solustikiyan{};
        char solucyan{};
        char solikiyan{};
        char sagikiyan{};
        char sagucyan{};
        char sagustucyan{};
        char sagustikiyan{};
        

        Symbol() = default;
        Symbol(char middleParam, int posParam, std::vector<std::string> datParam, int iParam){
            middle = middleParam;
            pos = posParam;
            dat = datParam;
            i = iParam;
            solustucyan = dat[i-1].at(pos-3);
            solustikiyan = dat[i-1].at(pos-2);
            topleft = dat[i-1].at(pos-1);
            top = dat[i-1].at(pos);
            topright = dat[i-1].at(pos+1);
            sagustikiyan = dat[i-1].at(pos+2);
            sagustucyan = dat[i-1].at(pos+3);
            left = dat[i].at(pos-1);
            solikiyan = dat[i].at(pos-2);
            solucyan = dat[i].at(pos-3);
            right = dat[i].at(pos+1);
            sagikiyan = dat[i].at(pos+2);
            sagucyan = dat[i].at(pos+3);
        }

        void setSudoku(char middleParam, int posParam, std::vector<std::string> datParam, int iParam){
            middle = middleParam;
            pos = posParam;
            dat = datParam;
            i = iParam;
            solustucyan = dat[i-1].at(pos-3);
            solustikiyan = dat[i-1].at(pos-2);
            topleft = dat[i-1].at(pos-1);
            top = dat[i-1].at(pos);
            topright = dat[i-1].at(pos+1);
            sagustikiyan = dat[i-1].at(pos+2);
            sagustucyan = dat[i-1].at(pos+3);
            left = dat[i].at(pos-1);
            solikiyan = dat[i].at(pos-2);
            solucyan = dat[i].at(pos-3);
            right = dat[i].at(pos+1);
            sagikiyan = dat[i].at(pos+2);
            sagucyan = dat[i].at(pos+3);
        }

};

int main() {
    std::fstream fin("engineparts.txt"); // Added fstream header

    if (!fin) {
        std::cerr << "Failed to open file." << std::endl;
        return 1;
    }

    std::vector<std::string> data;
    std::string line;

    while (std::getline(fin, line)) {
        std::replace(line.begin(), line.end(), '.', ' ');
        data.push_back(line);
    }

    for (int i = 0; i < data.size(); ++i) {
        for (int ii = 0; ii < data[i].length(); ++ii) { // Replaced line.length() with data[i].length()
            char c = data[i][ii];
            int pos {0};
            if(std::ispunct(c)){
                pos = data[i].find(c, ii);
                //std::cout <<"i : " << i << " c : " << c << " pos : " << pos << std::endl;
                Symbol s1(c, pos, data, i);
                s1.checkAround(c, pos, data, i);
                //std::cout << "==================" << std::endl;
                //std::cout << s1.topleft << s1.top << s1.topright << std::endl;
                //std::cout << s1.left << s1.middle << s1.right << std::endl;
                //std::cout << "==================" << std::endl;
            }
        }
    }

    return 0;
}