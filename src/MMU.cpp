#include "MMU.h"

MMU::MMU() {
    bios = new std::map<int, unsigned char>();
    rom = new std::map<int, unsigned char>();
    wram = new std::map<int, unsigned char>();
    eram = new std::map<int, unsigned char>();
    zram = new std::map<int, unsigned char>();
}

MMU::~MMU() {
    delete bios;
    delete rom;
    delete wram;
    delete eram;
    delete zram;
}

unsigned char MMU::rb(int addr) {
}

unsigned short int MMU::rw(int addr) {
}

void MMU::wb(int addr, unsigned char val) {
}

void MMU::ww(int addr, unsigned short int val) {
}