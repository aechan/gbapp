#pragma once
#include "MMU.h"

// initialize data structs and set bios mode
MMU::MMU() {
    bios = new std::map<uint8_t, uint8_t>();
    rom = new std::map<uint8_t, uint8_t>();
    wram = new std::map<uint8_t, uint8_t>();
    eram = new std::map<uint8_t, uint8_t>();
    zram = new std::map<uint8_t, uint8_t>();
    inbios = true;
}

// delete all memory
MMU::~MMU() {
    delete bios;
    delete rom;
    delete wram;
    delete eram;
    delete zram;
}

uint8_t MMU::rb(uint8_t addr) {
}

uint16_t MMU::rw(uint8_t addr) {
}

void MMU::wb(uint8_t addr, uint8_t val) {
}

void MMU::ww(uint8_t addr, uint16_t val) {
}