#include <iostream>
#include "../reutils.h"

int main()
{
    //Utils::Math::setDecimals(15);
    std::cout << ReUtils::Random::get(0, 10) << std::endl;

    return 0;
}