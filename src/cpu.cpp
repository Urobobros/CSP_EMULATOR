#include "cpu.h"
#include <iostream>

CPU::CPU(Memory &mem, Peripherals &periph)
    : memory(mem), peripherals(periph) {}

void CPU::reset() {
    pc = 0;
    acc = 0;
}

bool CPU::step() {
    if (pc >= memory.size())
        return false;
    uint8_t opcode = memory.read(pc++);
    switch (opcode) {
    case 0x00: // NOP
        break;
    case 0x04: // INC A
        ++acc;
        break;
    case 0x74: // MOV A, #imm
        acc = memory.read(pc++);
        break;
    case 0x75: { // MOV direct, #imm
        uint8_t addr = memory.read(pc++);
        uint8_t val = memory.read(pc++);
        memory.write(addr, val);
        break;
    }
    case 0xE4: // CLR A
        acc = 0;
        break;
    case 0x22: // RET (used as halt)
        return false;
    default:
        std::cout << "Unknown opcode: " << static_cast<int>(opcode) << "\n";
        return false;
    }
    return true;
}

void CPU::run() {
    int cycles = 0;
    while (step() && cycles < 100)
        ++cycles;
    std::cout << "CPU halted with A=" << static_cast<int>(acc) << std::endl;
}
