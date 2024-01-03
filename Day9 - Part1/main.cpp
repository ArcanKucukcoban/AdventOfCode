#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int extrapolate(std::vector<std::vector<int>> exData){

}

int main()
{
    std::ifstream fin("input.txt");
    if (!fin)
    {
        std::cerr << "Failed to load input.txt" << std::endl;
        return 1; // Added return statement to exit program in case of failure
    }

    std::vector<std::vector<int>> data; // vector of vectors to store arrays of integers
    std::string line;

    while (std::getline(fin, line))
    {
        std::vector<int> numbers; // array of integers for each line
        std::istringstream iss(line);
        int num;

        while (iss >> num)
        {
            numbers.push_back(num); // store each integer in the array
        }

        data.push_back(numbers); // store the array in the vector
    }

    /*
    #include <iostream>
    
    void recursiveFunction(int n)
    {
        // Base case: Stop recursion when n is 0
        if (n == 0)
            return;
    
        // Create a new array dynamically using 'new'
        int* newArray = new int[n];
    
        // Perform operations on the array or do other computations
    
        // Recursive call with a modified value of n
        recursiveFunction(n - 1);
    
        // Clean up the dynamically allocated array
        delete[] newArray;
    }
    
    int main()
    {
        int startingValue = 5;
        recursiveFunction(startingValue);
    
        return 0;
    }
    */

    return 0;
}