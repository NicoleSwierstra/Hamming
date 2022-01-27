#include <iostream>
#include <time.h>
#include <bitset>

#include "BitScrewer.hpp"
#include "Hamming.h"
#include "Hamming.cpp"

int main(void) {
    srand(time(nullptr));
    
    Hamming1511 a;
    a.setData(304);

    a.data[10] = !a.data[10]; 

    std::cout << "Message: " << std::bitset<11>(304) << "\n";
    std::cout << "Error:   " << std::bitset<11>(a.getDataRaw()) << "\n";
    int i = a.getData();
    std::cout << "Fixed:   " << std::bitset<11>(i);
}