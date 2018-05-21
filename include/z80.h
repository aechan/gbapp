typedef struct clock {
    uint8_t t;
    uint8_t m;
} zclock;

typedef struct registers {
    /**
     * 8 bit regs
     **/
    uint8_t a;
    uint8_t b;
    uint8_t c;
    uint8_t d;
    uint8_t e;
    uint8_t h; 
    uint8_t l;

    /**
     * !!Notes on FLAG!!
     * 0x80 - last op produced result of 0
     * 0x40 - last op was a subtraction
     * 0x20 - if last op result the lower half of the byte overflowed past 15
     * 0x10 - if last op was greater than 255 of less than 0 (if subtraction)
     **/
    uint8_t f;

    /**
     * 16 bit regs
     **/
    uint16_t pc;
    uint16_t sp;

    /**
     * clock for last instr set
     **/
    uint8_t m;
    uint8_t t;

} registers;

class z80 {
public:
    zclock _c;
    registers _r;
    
    /**
     * Misc instructions
     **/ 
    void NOP();     // NOP - no operation
    void reset();   // resets cpu for startup

    /**
     * Data load/store
     **/ 
    // Register A
    void ldr_aa();
    void ldr_ab();
    void ldr_ac();
    void ldr_ad();
    void ldr_ae();
    void ldr_ah();
    void ldr_al();

    // Register B
    void ldr_ba();
    void ldr_bb();
    void ldr_bc();
    void ldr_bd();
    void ldr_be();
    void ldr_bh();
    void ldr_bl();

    // Register C
    void ldr_ca();
    void ldr_cb();
    void ldr_cc();
    void ldr_cd();
    void ldr_ce();
    void ldr_ch();
    void ldr_cl();

    // Register D
    void ldr_da();
    void ldr_db();
    void ldr_dc();
    void ldr_dd();
    void ldr_de();
    void ldr_dh();
    void ldr_dl();

    // Register E
    void ldr_ea();
    void ldr_eb();
    void ldr_ec();
    void ldr_ed();
    void ldr_ee();
    void ldr_eh();
    void ldr_el();

    // Register H
    void ldr_ha();
    void ldr_hb();
    void ldr_hc();
    void ldr_hd();
    void ldr_he();
    void ldr_hh();
    void ldr_hl();

    // Register L
    void ldr_la();
    void ldr_lb();
    void ldr_lc();
    void ldr_ld();
    void ldr_le();
    void ldr_lh();
    void ldr_ll();

    /**
     * Pointer loaders
     **/ 
    void ldr_HLa();
    void ldr_HLb();
    void ldr_HLc();
    void ldr_HLd();
    void ldr_HLe();
    void ldr_HLh();
    void ldr_HLl();


    /**
     * Data processors
     **/ 
    void cmpr_b();  // compare B to A, set flags (CP A, B)
    void addr_e();  // add registr E to A leave result in A (ADD A, E)

};