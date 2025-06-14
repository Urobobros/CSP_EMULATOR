# CSP Emulator

This repository now contains two components:

1. **Python CSP solver** – A simple backtracking constraint solver used for demonstration and tests.
2. **C++ DSP emulator skeleton** – Initial modules to emulate the Creative CT1748A/ST18932 DSP using firmware binaries.

The emulator is organized into several modules under `src/`:

- `cpu.*` – CPU loop executing instructions from memory. A few 8051 opcodes
  (`NOP`, `MOV A,#imm`, `INC A`, `MOV direct,#imm`, `CLR A` and `RET`) are
  implemented as a starting point.
- `memory.*` – Simple memory storage with bounds checking
- `peripherals.*` – Placeholder DSP I/O handling
- `firmware.*` – Loading firmware `.bin` files (versions 4.04–4.16)
- `algorithms.*` – Stubs for ADPCM, Q‑Sound and TextAssist processing
- `main.cpp` – Example entry point wiring everything together

To run the emulator you must provide a firmware binary. Obtain one (versions 4.04–4.16) from [S95Sedan/CT1741_DSP](https://github.com/S95Sedan/CT1741_DSP) and set the `FIRMWARE_PATH` environment variable to its location. These firmware files remain the property of Creative Labs and are not distributed with this repository.

For development and tests the build system uses a tiny dummy firmware which
loads the value `0x05` into the accumulator, increments it and then halts.


## Building the C++ code

This project uses CMake. To build the emulator:

```bash
cmake -S . -B build
cmake --build build
```

Run the compiled example:

```bash
./build/csp_main
```

## Running the Python example and tests

```bash
python -m csp_emulator.example
pytest -q
```
