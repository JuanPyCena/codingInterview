//
// Created by Felix on 13.01.2022.
//

#include "helperfunctions.h"

bool test01()
{
    char* fileName = "C:\\Users\\Felix\\CLionProjects\\interview\\test.csv";
    auto numbers = helperFunctions::readNumbers(fileName, ' ');
    return true;
}

bool test02()
{
    std::vector<double> numbers = {1.0, 2.0, 3.0, 4.0, 5.0};
    auto outOfBounds = helperFunctions::outOfBounds(numbers);
    return outOfBounds == 0;
}


bool test03()
{
    std::vector<double> numbers = {-71, 2.0, 3.0, 4.0, 5.0};
    auto outOfBounds = helperFunctions::outOfBounds(numbers);
    return outOfBounds != 0;
}

bool test04()
{
    std::vector<double> numbers = {0, 2.0, 3.0, 4.0, 2.081e+9};
    auto outOfBounds = helperFunctions::outOfBounds(numbers);
    return outOfBounds != 0;
}

bool test05()
{
    std::vector<double> numbers = {1.0, 2.0, 3.0, 4.0, 5.0};
    auto result = helperFunctions::median(numbers);
    return result.first == 3.0 && result.second.size() == 1 && result.second[0] == 3;
}

bool test06()
{
    std::vector<double> numbers = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};
    auto result = helperFunctions::median(numbers);
    return result.first == 3.5 && result.second.size() == 2 && result.second[0] == 4 && result.second[1] == 3;
}

int main()
{
    bool ok = true;
    ok &= test01();
    ok &= test02();
    ok &= test03();
    ok &= test04();
    ok &= test05();
    ok &= test06();
    
    
    return ok ? 0 : 1;
}
