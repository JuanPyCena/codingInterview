#include <iostream>
#include "helperfunctions.h"

using namespace std;

int main(int argc, char **argv)
{
    // allow only excatly one argument which is the file name
    if (argc != 2)
    {
        cerr << "Invalid number of arguments" << endl;
        return 1;
    }
    
    // fileName is second element of argv
    auto fileName = argv[1];
    
    auto numbers = helperFunctions::readNumbers(fileName, ',');
    
    auto outOfBounds = helperFunctions::outOfBounds(numbers);
    
    if (outOfBounds != 0) return outOfBounds;
    
    // sort number ascending order
    sort(numbers.begin(), numbers.end());
    
    auto result = helperFunctions::median(numbers);
    auto median = result.first;
    auto usedNumbers = result.second;
    
    // print contents of numbers in ascending order and highlight used numbers
    cout << "Numbers in ascending order, numbers used for calculation in brackets: ";
    for (auto n : numbers)
    {
        if (find(usedNumbers.begin(), usedNumbers.end(), n) != usedNumbers.end())
            cout << "[" << n << "] ";
        else
            cout << n << " ";
    }
    
    cout << "\n\nMedian with precision of 2 values after the comma: " << median << endl;
    
    return 0;
}
