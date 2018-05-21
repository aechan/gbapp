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