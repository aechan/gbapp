#include "MMU.h"

MMU::MMU() {
    bytes = new std::map<int, unsigned char>();
    words = new std::map<int, unsigned short int>();
}

MMU::~MMU() {
    delete bytes;
    delete words;
}

unsigned char MMU::rb(int addr) {
    return this->bytes->at(addr);
}

unsigned short int MMU::rw(int addr) {
    return this->words->at(addr);
}

void MMU::wb(int addr, unsigned char val) {
    this->bytes->insert_or_assign(addr, val);
}

void MMU::ww(int addr, unsigned short int val) {
    this->words->insert_or_assign(addr, val);
}