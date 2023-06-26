cmake_minimum_required(VERSION 3.16)
project(RK1 C)

set(CMAKE_C_STANDARD 11)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(RK1.elf main.c src/game.c include/game.h src/args_check.c include/args_check.h)
target_link_libraries(RK1.elf ${CURSES_LIBRARIES})