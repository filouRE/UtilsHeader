#include <iostream>
#include "../reutils.h"
#include "example/test.cpp"

int main()
{
    std::cout << ReUtils::Math::pow(2, 3) << std::endl;
    test();

    return 0;
}