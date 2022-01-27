#include "Hamming.h"
#include <iostream>

void Hamming1511::setData(int i){
    std::bitset<11> bits(i);
    data[3]  = bits[0];
    data[5]  = bits[1];
    data[6]  = bits[2];
    data[7]  = bits[3];
    data[9]  = bits[4];
    data[10] = bits[5];
    data[11] = bits[6];
    data[12] = bits[7];
    data[13] = bits[8];
    data[14] = bits[9];
    data[15] = bits[10];

    data[1] = (data[3] + data[5] + data[7]  + data[9]  + data[11] + data[13] + data[15]) % 2;
    data[2] = (data[3] + data[6] + data[7]  + data[10] + data[11] + data[14] + data[15]) % 2;
    data[4] = (data[5] + data[6] + data[7]  + data[12] + data[13] + data[14] + data[15]) % 2;
    data[8] = (data[9] + data[10]+ data[11] + data[12] + data[13] + data[14] + data[15]) % 2;

    int b0;
    for(int i = 1; i < 16; i++){
        b0 += bits[i];
    }
    bits[0] = b0 % 2;
}

bool Hamming1511::checkData(){
    uint8_t location = 0;
    for(uint8_t i = 0; i < 16; i++){
        if(data[i]) location ^= i;
    }
    if(location == 0) return true;
    std::cout << (int)location << ": error location\n";
    data.flip(location);
    return true;
}

uint16_t Hamming1511::getDataRaw(){
     return data[15] * 1024 +
        data[14] * 512 +
        data[13] * 256 +
        data[12] * 128 +
        data[11] * 64 +
        data[10] * 32 +
        data[9] * 16 +
        data[7] * 8 +
        data[6] * 4 +
        data[5] * 2 +
        data[3] ;
}

uint16_t Hamming1511::getData(){
    if(checkData()){
        return getDataRaw();
    }
    return 0x0000;
}