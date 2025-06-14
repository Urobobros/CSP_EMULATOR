#include "memory.h"
#include <stdexcept>

Memory::Memory(size_t size) : data(size, 0) {}

uint8_t Memory::read(uint32_t addr) const {
    if (addr >= data.size()) throw std::out_of_range("read");
    return data[addr];
}

void Memory::write(uint32_t addr, uint8_t value) {
    if (addr >= data.size()) throw std::out_of_range("write");
    data[addr] = value;
}
