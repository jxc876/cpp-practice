# About

A project to practice C++ concepts

# Dependencies

The examples use the Boost library, you'll need to install it
* https://www.boost.org/doc/user-guide/getting-started.html

```shell
brew install boost
```

It also uses the Catch2 for testing
* https://github.com/catchorg/Catch2/

```shell
brew info catch2
```

# Building

Use CMake to build the programs

```shell
cmake -B build
cmake --build build # or make -C build
```

# Running

To run a specific program:

```shell
./build/main
./build/point
# etc...
```

To run all tests:

```shell
./build/tests
Randomness seeded to: 3370175609
===============================================================================
All tests passed (6 assertions in 2 test cases)
```

Or with `ctest` (part of Cmake)

```shell
ctest --test-dir build
# ..
100% tests passed, 0 tests failed out of 2
Total Test time (real) =   0.01 sec
```
