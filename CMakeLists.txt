cmake_minimum_required(VERSION 3.31)
project(cpp_practice)

set(CMAKE_CXX_STANDARD 20)

find_package(Boost REQUIRED)

add_executable(main main.cpp)
add_executable(person person.cpp)
add_executable(names1 names1.cpp)
add_executable(names2 names2.cpp)
add_executable(point point.cpp)
add_executable(names3 names3.cpp)

add_executable(smartptr smartptrs.cpp)
target_link_libraries(smartptr Boost::headers)
