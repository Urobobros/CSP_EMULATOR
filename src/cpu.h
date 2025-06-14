#ifndef CSP_EMULATOR_CPU_H
#define CSP_EMULATOR_CPU_H

#include <cstdint>
#include "memory.h"
#include "peripherals.h"

class CPU {
public:
    CPU(Memory &mem, Peripherals &periph);
    void reset();
    void run();
private:
    bool step();
    Memory &memory;
    Peripherals &peripherals;
    uint16_t pc = 0;
    uint8_t acc = 0;
};

#endif // CSP_EMULATOR_CPU_H
