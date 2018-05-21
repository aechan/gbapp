#pragma once
#include "z80.h"

int main() {
    z80 z;
    z.NOP();
    z.addr_e();
    z.cmpr_b();
    return 0;
}