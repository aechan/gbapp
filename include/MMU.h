class MMU {
public:
    // read byte
    unsigned char rb(int addr);
    // read word
    unsigned short int wb(int addr);

    // write byte
    void wb(int addr, unsigned char val);

    // write word
    void ww(int addr, unsigned short int val);
};