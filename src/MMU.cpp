#include "MMU.h"

// initialize data structs and set bios mode
MMU::MMU(z80* cpu) {
    this->cpu = cpu;
    bios = new std::map<uint16_t, uint8_t>();
    rom = new std::map<uint16_t, uint8_t>();
    wram = new std::map<uint16_t, uint8_t>();
    eram = new std::map<uint16_t, uint8_t>();
    zram = new std::map<uint16_t, uint8_t>();
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

uint8_t MMU::rb(uint16_t addr) {
    switch(addr & 0xF000) {
        case 0x0000:
           if(this->inbios) {
               if(addr < 0x0100) return this->bios[addr];
               else if(this->cpu->_r.pc == 0x0100)
                this->inbios = false;
           } 
           return this->rom[addr];

        case 0x1000:
        case 0x2000:
        case 0x3000:
            return this->rom[addr];
        case 0x4000:
        case 0x5000:
        case 0x6000:
        case 0x7000:
            return this->rom[addr];

        case 0x8000:
        case 0x9000:
            // gpu region, unimplemented so far
            return 0;
        case 0xA000:
        case 0xB000:
            return this->eram[addr & 0x1FFF];

        case 0xC000:
        case 0xD000:
            return this->wram[addr & 0x1FFF];
        case 0xE000:    // wram shadow
            return this->wram[addr & 0x1FFF];
        case 0xF000:
            switch(addr & 0x0F00) {
                case 0x000: case 0x100: case 0x200: case 0x300:
		        case 0x400: case 0x500: case 0x600: case 0x700:
		        case 0x800: case 0x900: case 0xA00: case 0xB00:
		        case 0xC00: case 0xD00:
                    return this->wram[addr & 0x1FFF];
                case 0xE00:
                    if(addr < 0xFEA0)
                        return 0; //gpu oam unimplemented
                    else return 0;
                // zero page mem
                case 0xF00:
                    if(addr >= 0xFF80) {
                        return this->zram[addr & 0x7F];
                    } else {
                        return 0;
                    }
            }
    }
}

uint16_t MMU::rw(uint16_t addr) {
    return this->rb(addr) + (this->rb(addr+1) << 8);
}

void MMU::wb(uint16_t addr, uint8_t val) {
}

void MMU::ww(uint16_t addr, uint16_t val) {
}