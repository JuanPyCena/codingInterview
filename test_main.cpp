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
    char* fileName = "C:\\Users\\Felix\\CLionProjects\\interview\\test.csv";
    auto numbers = helperFunctions::readNumbers(fileName, ' ');
    auto outOfBounds = helperFunctions::outOfBounds(numbers);
    return outOfBounds == 0;
}


bool test03()
{
    char* fileName = "C:\\Users\\Felix\\CLionProjects\\interview\\test1.csv";
    auto numbers = helperFunctions::readNumbers(fileName, ' ');
    auto outOfBounds = helperFunctions::outOfBounds(numbers);
    return outOfBounds != 0;
}

int main()
{
    bool ok = true;
    ok &= test01();
    ok &= test02();
    ok &= test03();
    
    
    return ok ? 0 : 1;
}
