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
    std::map<int, unsigned char>* bytes;
    std::map<int, unsigned short int>* words;
};