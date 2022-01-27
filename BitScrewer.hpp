#pragma once
#include <stdlib.h>

template <typename T>
inline void screw1Bit(T& t) {
    int x = 1 << (rand() % ((8 * sizeof(t)) - 1));
    t = t ^ x;
}

template <typename T>
inline void screw2Bits(T& t){
    screw1Bit(t);
    screw1Bit(t);
}