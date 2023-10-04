#include <iostream>
#include "../reutils.h"

int main()
{
    //Utils::Math::setDecimals(10);

    std::cout << Utils::Math::Constants::PI << std::endl;

    Utils::Math::setDecimals(24);
    std::cout << Utils::Math::Constants::PI << std::endl;

    return 0;
}