#include "firmware.h"
#include <fstream>

bool Firmware::load_binary(const std::string &path) {
    std::ifstream file(path, std::ios::binary);
    if (!file)
        return false;
    data.assign((std::istreambuf_iterator<char>(file)),
                std::istreambuf_iterator<char>());
    return true;
}

void Firmware::load_into_memory(Memory &mem) const {
    for (size_t i = 0; i < data.size() && i < mem.size(); ++i) {
        mem.write(static_cast<uint32_t>(i), data[i]);
    }
}
