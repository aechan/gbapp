#include <map>
#include <stdint.h>

class MMU {
public:
    // read byte
    uint8_t rb(uint16_t addr);
    // read word
    uint16_t rw(uint16_t addr);

    // write byte
    void wb(uint16_t addr, uint8_t val);
    // write word
    void ww(uint16_t addr, uint16_t val);

    // ctor/dtor
    MMU();
    ~MMU();
private:
    std::map<uint16_t, uint8_t>* bios;
    std::map<uint16_t, uint8_t>* rom;
    std::map<uint16_t, uint8_t>* wram;
    std::map<uint16_t, uint8_t>* eram;
    std::map<uint16_t, uint8_t>* zram;

    bool inbios;
};