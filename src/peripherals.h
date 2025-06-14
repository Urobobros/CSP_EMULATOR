#ifndef CSP_EMULATOR_PERIPHERALS_H
#define CSP_EMULATOR_PERIPHERALS_H

#include <cstdint>

class Peripherals {
public:
    void write_io(uint16_t port, uint8_t value);
    uint8_t read_io(uint16_t port) const;
};

#endif // CSP_EMULATOR_PERIPHERALS_H
