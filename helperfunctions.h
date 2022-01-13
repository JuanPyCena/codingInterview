//
// Created by Felix on 13.01.2022.
//

#ifndef INTERVIEW_HELPERFUNCTIONS_H
#define INTERVIEW_HELPERFUNCTIONS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

const int UPPER_BOUND = 2.08e+9;
const int LOWER_BOUND = -70;

using namespace std;
class helperFunctions
{
private:
    static double precision(double value) {
        return ((int)(value * 100 + .5) / 100.0);
    }
    
public:
    static std::vector<double> readNumbers(char* fileName, char sep) {
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
    static int outOfBounds(vector<double> numbers) {

        auto outOfBounds = find_if(numbers.begin(), numbers.end(), [](int n) { return n < LOWER_BOUND || n > UPPER_BOUND; });
        // throw error if number are out of bounds
        if (outOfBounds != numbers.end())
        {
            cerr << "Invalid number in file, numbers must be between " << LOWER_BOUND << " and " << UPPER_BOUND << " but are: ";
            for (auto n : numbers)
                cerr << n << " ";
            return 1;
        }
        
        return 0;
    }
    static pair<double, vector<double>> median(vector<double> numbers)
    {
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
        
        return make_pair(median, usedNumbers);
    }
    
};


#endif //INTERVIEW_HELPERFUNCTIONS_H
