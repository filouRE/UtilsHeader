#include <iostream>
#include "../reutils.h"

int main()
{
    Utils::Math::setDecimals(15);
    std::cout << Utils::Math::Constants::PI << std::endl;

    return 0;
}