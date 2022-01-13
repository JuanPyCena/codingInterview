#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

const int UPPER_BOUND = 2.08e+9;
const int LOWER_BOUND = -70;

using namespace std;

vector<double> readNumbers(char* fileName, char sep) {
    ifstream file(fileName);
    
    // Exit if file cannot be opened
    if (!file)
    {
        cerr << "\aError opening file.\n\n";
        exit(EXIT_FAILURE);
    }
    
    vector<double> numbers;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string number;
        while (getline(ss, number, sep)) {
            numbers.push_back(stod(number));
        }
    }
    return numbers;
}
double precision(double value) {
    return ((int)(value * 100 + .5) / 100.0);
}

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
    
    auto numbers = readNumbers(fileName, ',');
    
    auto outOfBounds = find_if(numbers.begin(), numbers.end(), [](int n) { return n < LOWER_BOUND || n > UPPER_BOUND; });
    // throw error if number are out of bounds
    if (outOfBounds != numbers.end())
    {
        cerr << "Invalid number in file, numbers must be between " << LOWER_BOUND << " and " << UPPER_BOUND << " but are: ";
        for (auto n : numbers)
            cerr << n << " ";
        return 1;
    }
    
    // sort number ascending order
    sort(numbers.begin(), numbers.end());
    
    // calcualte median from numbers
    // if odd number of numbers, take middle number
    // if even number of numbers, take average of middle two numbers
    double median = 0.0;
    bool isEven = numbers.size() % 2 == 0;
    vector<double> usedNumbers;
    if (isEven)
    {
        int middle = numbers.size() / 2;
        median = precision((numbers[middle] + numbers[middle - 1]) / 2);
        usedNumbers.push_back(numbers[middle]);
        usedNumbers.push_back(numbers[middle - 1]);
    }
    else
    {
        int middle = numbers.size() / 2;
        median = precision(numbers[middle]);
        usedNumbers.push_back(numbers[middle]);
    }
    
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
