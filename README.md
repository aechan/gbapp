# GBA++🕹️

Gameboy Advanced emulator implemented in C++17

First, all the original gameboy's hardware will be emulated since it's a simpler system and then the rest of the gameboy advance's more *advanced* hardware will be built on.

Currently working on the simulated MMU (Memory Management Unit) in order to finish the implementation of all of the z80's instructions.

Will use SDL for cross platform input, audio and to create the OpenGL context.

## Planned phases
1. CPU - in progress
2. Memory - in progress
3. GPU Timings
4. Graphics
5. Integration
6. Input
7. Sprites
8. Interrupts
9. Memory Banking
10. Timers

## Development Guidelines

### Tests
GBA++ uses the [catch2](https://github.com/catchorg/Catch2) testing framework. To write a test, simply create a file in the `src/` directory and name it `*_tests.cpp` where `*` is any name, usually the name of the class we are writing tests for. Then, to build the tests, run `make tests`. This will rebuild the `gba_tests` executable which can then be run to see the results of the tests. The main test file is the `all_tests.cpp` file. It `#define`s the `CATCH_CONFIG_MAIN` symbol so catch will mark it as the main test file. This file should remain that way and all test cases need to be in external `*_tests.cpp` files.

#### Test file format:
All test files need to have at a minimum:
```cpp
#include "catch.hpp"
```
This will ensure that the file is found as a test file by `catch2` and will be included into `all_tests.cpp` and have all its `TEST_CASE`s run. See the [catch2](https://github.com/catchorg/Catch2) docs for more info on how to write test cases.