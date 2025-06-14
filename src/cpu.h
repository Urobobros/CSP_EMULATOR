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
    Memory &memory;
    Peripherals &peripherals;
    uint32_t pc = 0;
};

#endif // CSP_EMULATOR_CPU_H
