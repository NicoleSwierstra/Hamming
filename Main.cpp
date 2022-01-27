#include <iostream>
#include <time.h>
#include <bitset>

#include "BitScrewer.hpp"

int main(void) {
    srand(time(nullptr));
    
    char a = 0;

    std::bitset<8> x(a);
    screw1Bit(a);
    std::bitset<8> y(a);
    std::cout << x << '\n' << y << '\n' << h << '\n';
}