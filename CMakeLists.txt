cmake_minimum_required(VERSION 3.19)
project(rushhour)

set(CMAKE_CXX_STANDARD 20)
set(EXECUTABLE_OUTPUT_PATH "../bin/")
add_executable(rushhour.out src/main.cpp src/board.cpp src/board.h src/vehicle.cpp src/vehicle.h src/main.h src/Astar.cpp src/Astar.h)

#set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "rushhour.out")