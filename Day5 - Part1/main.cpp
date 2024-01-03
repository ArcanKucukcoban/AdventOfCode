#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int shortestpath(std::vector<int> vecintParam)
{
    int temp = vecintParam.at(0);
    for (int i{0}; i < vecintParam.size(); ++i)
    {
        if (vecintParam.at(i) < temp)
        {
            temp = vecintParam.at(i);
        }
    }
    std::cout << "Shortest location : " << temp << std::endl;
    return temp;
}

int calculation(std::vector<std::vector<std::string>> sectionsParam, std::vector<int> intseedsParam)
{
    std::vector<int> drs;
    std::vector<int> srs;
    std::vector<int> rl;

    for (int i{0}; i < sectionsParam.size(); ++i)
    {
        for (int ii{0}; ii < (sectionsParam.at(i)).size(); ++ii)
        {
            if (std::isdigit(((sectionsParam.at(i)).at(ii))[0]))
            {
                std::istringstream iss((sectionsParam.at(i)).at(ii));
                std::string dr, sr, r;
                while ((iss >> dr >> sr >> r))
                {
                    drs.push_back(std::stoi(dr));
                    srs.push_back(std::stoi(sr));
                    rl.push_back(std::stoi(r));
                }
            }
        }

        std::vector<int> maxrange;
        std::vector<int> minrange;

        for (int i{0}; i < srs.size(); ++i)
        {
            maxrange.push_back((srs.at(i) + rl.at(i)) - 1);
            minrange.push_back(srs.at(i));

            for (int ii{0}; ii < intseedsParam.size(); ++ii)
            {
                if (intseedsParam.at(ii) >= minrange.at(i) && intseedsParam.at(i) < maxrange.at(i))
                {
                    if ((srs.at(i) - drs.at(i)) < 0)
                    {
                        intseedsParam.at(ii) = intseedsParam.at(ii) + (drs.at(i) - srs.at(i));
                    }
                    else if ((srs.at(i) - drs.at(i)) > 0)
                    {
                        intseedsParam.at(ii) = (intseedsParam.at(ii) - srs.at(i)) + (drs.at(i));
                    }
                }
                else if (intseedsParam.at(ii) > 0 &&
                         intseedsParam.at(ii) < minrange.at(i) &&
                         !(intseedsParam.at(ii) >= minrange.at(i) &&
                           intseedsParam.at(i) < maxrange.at(i)))
                {
                    continue;
                }
            }
        }
    }

    return shortestpath(intseedsParam);
}

int main()
{
    std::ifstream inputFile("seeds.txt");
    if (!inputFile)
    {
        std::cout << "Failed to open the file." << std::endl;
        return 1;
    }

    std::vector<std::vector<std::string>> sections;

    std::string line;
    std::vector<std::string> currentSection;

    while (std::getline(inputFile, line))
    {
        if (line.empty())
        {
            if (!currentSection.empty())
            {
                sections.push_back(currentSection);
                currentSection.clear();
            }
        }
        else
        {
            currentSection.push_back(line);
        }
    }

    if (!currentSection.empty())
    {
        sections.push_back(currentSection);
    }

    
    std::vector<int> intseeds;

    std::istringstream iss((sections.at(0)).at(0));
    std::string head, n1, n2, n3, n4;
    while (iss >> head >> n1 >> n2 >> n3 >> n4)
    {
        intseeds.push_back(std::stoi(n1));
        intseeds.push_back(std::stoi(n2));
        intseeds.push_back(std::stoi(n3));
        intseeds.push_back(std::stoi(n4));
    }

    calculation(sections, intseeds);

    return 0;
}