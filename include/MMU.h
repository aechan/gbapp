#include <map>

class MMU {
public:
    // read byte
    unsigned char rb(int addr);
    // read word
    unsigned short int rw(int addr);

    // write byte
    void wb(int addr, unsigned char val);

    // write word
    void ww(int addr, unsigned short int val);

    MMU();
    ~MMU();
private:
    std::map<int, unsigned char>* bios;
    std::map<int, unsigned char>* rom;
    std::map<int, unsigned char>* wram;
    std::map<int, unsigned char>* eram;
    std::map<int, unsigned char>* zram;
};