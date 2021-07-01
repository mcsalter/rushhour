cmake_minimum_required(VERSION 3.19)
project(rushhour_clion)

set(CMAKE_CXX_STANDARD 20)
set(EXECUTABLE_OUTPUT_PATH "../bin/")
add_executable(rushhour_clion src/main.cpp src/board.cpp src/board.h src/vehicle.cpp src/vehicle.h)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "rushhour.out")