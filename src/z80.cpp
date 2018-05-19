#include "z80.h"
#include "MMU.h"
/**
 * Add E to A
 **/
void z80::addr_e() {
    // add e to a
    this->_r.a += this->_r.e;
    // clear flags
    this->_r.f = 0;
    if(!(this->_r.a & 255)) this->_r.f |= 0x80; // check 0
    if(this->_r.a > 255) this->_r.f |= 0x10;    // check carry
    this->_r.a &= 255;
    this->_r.m = 1;
    this->_r.t = 4; 
}

/**
 * Compare register B to A, and set flag
 **/
void z80::cmpr_b() {
    unsigned char temp_a = this->_r.a;
    temp_a -= this->_r.b;
    this->_r.f |= 0x40; // set the subtraction flag
    if(!(temp_a & 255)) this->_r.f |= 0x80;
    if(temp_a < 0) this->_r.f |= 0x10;
    this->_r.m = 1;
    this->_r.t = 4;
}

/**
 * Implement the NOP no-operation instruction
 * Simply passes time
 **/
void z80::NOP() {
    this->_r.m = 1;
    this->_r.t = 4;
}

/**
 * resets the cpu back to the start of execution
 **/
void z80::reset() {
    this->_r.a = 0;
    this->_r.b = 0;
    this->_r.c = 0;
    this->_r.d = 0;
    this->_r.e = 0;
    this->_r.h = 0;
    this->_r.l = 0;
    this->_r.f = 0;
    this->_r.pc = 0;
    this->_r.sp = 0;
    this->_c.m = 0;
    this->_c.t = 0;
}