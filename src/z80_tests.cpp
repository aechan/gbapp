#include "catch.hpp"
#include "z80.h"
#include <iostream>

TEST_CASE("CASE: INSTR - ADD A, E") {
    z80 cpu;
    cpu._r.a = 3;
    cpu._r.e = 4;
    cpu.addr_e();
    REQUIRE(cpu._r.a == 7);
}

TEST_CASE("CASE: INSTR - ADD A, E - CHECK FLAG") {
    z80 cpu;
    cpu._r.f = 0x20; // set flag to have a previous state.
    cpu._r.a = 0;
    cpu._r.e = 0;
    cpu.addr_e();   // produce result of 0 to check that flag is set correctly
    REQUIRE(cpu._r.a == 0);
    REQUIRE(cpu._r.f == 0x80);
}