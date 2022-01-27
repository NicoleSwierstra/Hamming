#pragma once
#include <cstdint>
#include <bitset>

class Hamming1511 {
private:
    bool checkData();

public:
    uint16_t getDataRaw();
    uint16_t getData();
    std::bitset<16> data;
    //Hamming1511& operator=(int i) { setData(i); return *this; }
    void setData(int i);
};