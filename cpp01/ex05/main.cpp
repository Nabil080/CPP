#include "Harl.hpp"
#include <iostream>

int main(void)
{
    Harl    harl;

    harl.complain("DEBUG");
    harl.complain("WARNING");
    harl.complain("random");
    return 0;
}
