typedef struct clock {
    int t;
    int m;
} zclock;

typedef struct registers {
    /**
     * 8 bit regs
     **/
    unsigned char a;
    unsigned char b;
    unsigned char c;
    unsigned char d;
    unsigned char e;
    unsigned char h; 
    unsigned char l;

    /**
     * !!Notes on FLAG!!
     * 0x80 - last op produced result of 0
     * 0x40 - last op was a subtraction
     * 0x20 - if last op result the lower half of the byte overflowed past 15
     * 0x10 - if last op was greater than 255 of less than 0 (if subtraction)
     **/
    unsigned char f;

    /**
     * 16 bit regs
     **/
    unsigned short int pc;
    unsigned short int sp;

    /**
     * clock for last instr set
     **/
    int m;
    int t;

} registers;

class z80 {
public:
    zclock _c;
    registers _r;
    void addr_e();  // add registr E to A leave result in A (ADD A, E)
    void cmpr_b();  // compare B to A, set flags (CP A, B)
    void NOP();     // NOP - no operation
    void reset();   // resets cpu for startup
};