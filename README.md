# Monte Carlo AI | Hex-Game
A console Hex Game implementation using C++. The game AI uses a Monte Carlo approach to randomly populate the board and measure the effectiveness of each tile.

## Requirements
- C++14 compiler.
- CMake version 3.27 or greater.
- Make version 4.4.1 or greater (GNU Make).

## Installation
1. Create a folder called `build` inside the project folder.
2. Open a terminal and run the following command to generate makefiles: ``cmake -G "MinGW Makefiles" -S ./ -D CMAKE_C_COMPILER=gcc CMAKE_CXX_COMPILER=g++ -B build``
3. Navigate to the build folder: ``cd build``
4. Compile the game: ``mingw32-make -f Makefile # Windows`` and ``make -f Makefile # Linux/Mac``
5. Run tests (optional): ``ctest ``

## Troubleshooting
- If using a different CMake generator, change the `-G "MinGW Makefiles"` parameter.
- Get a list of available generators with `cmake --help`.
- Before changing CMake configuration, delete all files in the `build` folder.
- For CLion users, open the project and build within the IDE.
- Avoid using the CLion terminal to run the game due to execution delays.



 