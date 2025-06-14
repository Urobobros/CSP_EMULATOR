#include "cpu.h"
#include "firmware.h"
#include "algorithms.h"
#include <iostream>
#include <cstdlib>

int main() {
    Memory mem(256);
    Peripherals periph;
    CPU cpu(mem, periph);

    const char *env = std::getenv("FIRMWARE_PATH");
    std::string path = env ? env : "firmware/firmware.bin";

    Firmware fw;
    if (!fw.load_binary(path)) {
        std::cerr << "Failed to load firmware: " << path << std::endl;
        return 1;
    }
    fw.load_into_memory(mem);

    cpu.reset();
    cpu.run();

    Algorithms::process_adpcm();
    Algorithms::process_qsound();
    Algorithms::process_textassist();

    return 0;
}
