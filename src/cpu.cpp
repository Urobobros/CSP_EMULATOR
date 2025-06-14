#include "cpu.h"
#include <iostream>

CPU::CPU(Memory &mem, Peripherals &periph)
    : memory(mem), peripherals(periph) {}

void CPU::reset() {
    pc = 0;
}

void CPU::run() {
    // Very naive placeholder loop
    for (int i = 0; i < 10; ++i) {
        uint8_t opcode = memory.read(pc++);
        // In a full emulator, decode and execute opcode here
        std::cout << "Executing opcode: " << static_cast<int>(opcode) << "\n";
    }
}
