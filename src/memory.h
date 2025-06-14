#ifndef CSP_EMULATOR_MEMORY_H
#define CSP_EMULATOR_MEMORY_H

#include <vector>
#include <cstdint>

class Memory {
public:
    explicit Memory(size_t size);
    uint8_t read(uint32_t addr) const;
    void write(uint32_t addr, uint8_t value);
    size_t size() const { return data.size(); }
private:
    std::vector<uint8_t> data;
};

#endif // CSP_EMULATOR_MEMORY_H
