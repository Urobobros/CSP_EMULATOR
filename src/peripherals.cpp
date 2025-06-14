#include "peripherals.h"
#include <iostream>

void Peripherals::write_io(uint16_t port, uint8_t value) {
    std::cout << "Write IO port " << port << " value " << static_cast<int>(value) << "\n";
}

uint8_t Peripherals::read_io(uint16_t port) const {
    std::cout << "Read IO port " << port << "\n";
    return 0;
}
