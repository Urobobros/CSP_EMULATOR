#ifndef CSP_EMULATOR_FIRMWARE_H
#define CSP_EMULATOR_FIRMWARE_H

#include <string>
#include "memory.h"

class Firmware {
public:
    bool load_binary(const std::string &path);
    void load_into_memory(Memory &mem) const;
private:
    std::vector<uint8_t> data;
};

#endif // CSP_EMULATOR_FIRMWARE_H
