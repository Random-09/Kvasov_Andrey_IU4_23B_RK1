cmake_minimum_required(VERSION 3.22)
project(RK1 C)

set(CMAKE_C_STANDARD 11)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(RK1.elf main.c)
target_link_libraries(RK1.elf ${CURSES_LIBRARIES})