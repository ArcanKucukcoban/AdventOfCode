#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::ifstream fin("input.txt");
    if (!fin)
    {
        std::cerr << "Failed to load input.txt" << std::endl;
        return 1; // Added return statement to exit program in case of failure
    }

    std::vector<std::string> data;
    std::string line;
    std::vector<std::string> first;
    std::vector<std::string> second;
    std::vector<std::string> third;
    std::string start{"AAA"};
    std::string end{"ZZZ"};

    while (std::getline(fin, line))
    {
        line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());
        line.erase(std::remove(line.begin(), line.end(), '('), line.end());
        line.erase(std::remove(line.begin(), line.end(), ')'), line.end());
        if (!line.empty())
        {
            data.push_back(line);
        }
    }

    std::string instructions{data[0]};
    int startPos{0};
    for (int i{1}; i < data.size(); ++i)
    {
        std::istringstream iss(data[i]);

        std::string firstVal, secondVal, thirdVal; // Changed variables to store values

        std::getline(iss, firstVal, '=');  // Store value in firstVal till "="
        std::getline(iss, secondVal, ','); // Store value in secondVal til ","
        std::getline(iss, thirdVal);       // Store value in thirdVal til '\n'

        first.push_back(firstVal);   // Add value to first vector
        second.push_back(secondVal); // Add value to second vector
        third.push_back(thirdVal);   // Add value to third vector
    }

    bool notfound = true;
    int steps{0};
    int len = instructions.length();
    int index{0};
    std::string temp1 = "";
    std::string temp2 = "";
    std::string temp3 = "";

    while (notfound)
    {
        for (int i{0}; i < first.size(); ++i)
        {
            // first vektöründe start'ı bul.
            // instructions'da sıradaki harf L ise start = second[i], değil ise start = third[i] yap.
            // step sayısını arttır.

            // second veya third hangisi seçildi ise end'e eşit mi diye bak.
            // End'e eşit ise found = true yap while'ı boz.
            // Steps'i yazdır.
            // first[0], second[0], third[0]'ı al temp1 temp2 temp3'e eşitle. i indexli valueları al first[0]... eşitle. templeri de i valuelarına eşitle.

            // instructions'ın array indexini arttır sonraki döngü için.

            // std::cout << "Begin i : " << i << " " << first[i] << " " << second[i] << " " << third[i] << std::endl;
            // std::cout << "Begin start : " << start << " index : " << index << " steps : " << steps << std::endl;
            if ((first[i] == start))
            {
                if (instructions[index] == 'L')
                {
                    std::cout << " start : " << start << std::endl;
                    // swap
                    temp1 = first[i];
                    temp2 = second[i];
                    temp3 = third[i];
                    first[i] = first[0];
                    second[i] = second[0];
                    third[i] = third[0];
                    first[0] = temp1;
                    second[0] = temp2;
                    third[0] = temp3;

                    if (start == end)
                    {
                        notfound = false;
                        break;
                    }

                    ++steps;
                    ++index;
                    index %= len;
                    i = 0;
                    start = second[i];
                    std::cout << "left steps : " << steps << " i : " << i << " index : " << index << " start : " << start << std::endl;
                }
                else if (instructions[index] == 'R')
                {
                    std::cout << " start : " << start << std::endl;
                    // swap
                    temp1 = first[i];
                    temp2 = second[i];
                    temp3 = third[i];
                    first[i] = first[0];
                    second[i] = second[0];
                    third[i] = third[0];
                    first[0] = temp1;
                    second[0] = temp2;
                    third[0] = temp3;

                    if (start == end)
                    {
                        notfound = false;
                        break;
                    }

                    ++steps;
                    ++index;
                    index %= len;
                    i = 0;
                    start = third[i];
                    std::cout << "right steps : " << steps << " i : " << i << " index : " << index << " start : " << start << std::endl;

                    // std::cout << "Right i : " << i << " " << first[i] << " " << second[i] << " " << third[i]
                    // << " right start : " << start << " index : " << index << " steps : " << steps
                    // << " temp3 : " << temp3 << " first[0] : " << first[0] << " second[0] : " << second[0] << " third[0] : " << third[0]
                    // << std::endl;
                }
            }
        }
    }

    std::cout << "While loop is done" << std::endl;

    return 0;
}