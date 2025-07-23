cmake_minimum_required(VERSION 3.31)
project(cpp_practice)

set(CMAKE_CXX_STANDARD 20)

# libraries
find_package(Boost REQUIRED)
find_package(Catch2 3 REQUIRED)

add_executable(main main.cpp)
add_executable(person person.cpp)
add_executable(person2 person2.cpp)
add_executable(person3 person3.cpp)
add_executable(names1 names1.cpp)
add_executable(names2 names2.cpp)
add_executable(names3 names3.cpp)
add_executable(point point.cpp)
add_executable(copy copycons.cpp)
add_executable(smartptr smartptrs.cpp)
target_link_libraries(smartptr Boost::headers)

# tests
include(CTest)
include(Catch)
add_executable(tests
        test_factorial.cpp
        test_math.cpp
        test_array.cpp)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
catch_discover_tests(tests)