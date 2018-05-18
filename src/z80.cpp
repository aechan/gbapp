#include "z80.h"

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
    
}