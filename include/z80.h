typedef struct clock {
    int t;
    int m;
} clock;

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
    clock _c;
    registers _r;
    void addr_e();  // add registr E to A leave result in A (ADD A, E)
    void cmpr_b();  // compare B to A, set flags (CP A, B)
    void NOP();     // NOP - no operation
    void reset();   // resets cpu for startup
};