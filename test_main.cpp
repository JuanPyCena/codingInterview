//
// Created by Felix on 13.01.2022.
//

#include <he

bool test01()
{
    auto fileName = "doesNotExist.csv"
    
    return true;
}

int main()
{
    bool ok = true;
    ok &= test01();
    
    
    return ok ? 0 : 1;
}