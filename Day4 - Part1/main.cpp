#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cmath>

int main() {
    std::fstream fin("scratchcards.txt");
    std::vector<std::string> data;
    std::string line;
    int total {};
    std::string card[210];
    std::string winning[10]{};
    std::string played[25]{};
    int count[211]{};


    while (std::getline(fin, line)) {
        data.push_back(line);
    }

    for (int i{}; i < data.size(); ++i) {
        size_t colonPos = data[i].find(':');
        size_t tokenPos = data[i].find('|');
        if (colonPos != std::string::npos) {
            card[i] = data[i].substr(0, colonPos);
            winning[i] = data[i].substr(colonPos+1, tokenPos-colonPos-1);
            played[i] = data[i].substr(tokenPos+1, data[i].length());
            //std::cout << "card[" << i << "] : " << card[i] << std::endl;
            //std::cout << "winning[" << i << "] : " << winning[i] << std::endl;
            //std::cout << "played[" << i << "] : " << played[i] << std::endl;

            // Convert winning[i] to integer groups
            std::vector<int> winningInts;
            std::string group;
            for (char c : winning[i]) {
                if (std::isdigit(c)) {
                    group += c;
                } else if (!group.empty()) {
                    winningInts.push_back(std::stoi(group));
                    group.clear();
                }
            }
            if (!group.empty()) {
                winningInts.push_back(std::stoi(group));
            }

            // Convert played[i] to integer groups
            std::vector<int> playedInts;
            std::string group1;
            for (char c : played[i]) {
                if (std::isdigit(c)) {
                    group1 += c;
                } else if (!group1.empty()) {
                    playedInts.push_back(std::stoi(group1));
                    group1.clear();
                }
            }
            if (!group1.empty()) {
                playedInts.push_back(std::stoi(group1));
            }
            /*
            // Print the integer groups
            std::cout << "winning integers[" << i << "] : ";
            for (int num : winningInts) {
                std::cout << num << " ";
            }
            std::cout << std::endl;

            // Print the integer groups
            std::cout << "played integers[" << i << "] : ";
            for (int num : playedInts) {
                std::cout << num << " ";
            }
            std::cout << std::endl;
            */
            int match{0};
            for(int m{}; m<10; ++m){
                for(int n{}; n<25; ++n){
                    if(winningInts[m] == playedInts[n]){
                        //std::cout << "cardNo : " << i << " winningInts[" << m << "] : " <<  winningInts[m] << " playedInts[" << n << "] : " << playedInts[n] << std::endl;
                        ++match;
                    }
                }
            }
            //std::cout << "i : " << i << "Match : " <<  match << std::endl;
            if(match > 0){
                double result = std::pow(2,(match-1));
                total += result;
                std::cout << "result : " << result << " total : " << total << std::endl;

            }
            //std::cout << "i : " << i << " match : " << match << " total : " << total << std::endl;
        }
    }

    return 0;
}