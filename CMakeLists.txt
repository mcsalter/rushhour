cmake_minimum_required(VERSION 3.19)
project(rushhour-solver)
set(CMAKE_CXX_STANDARD 20)
set(cmake_binary_dir ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)



add_executable(rushhour.out main.cpp)
target_link_libraries(rushhour.out board.cpp)

add_library(board.cpp board.cpp)
target_link_libraries(board.cpp vehicle.cpp)

add_library(vehicle.cpp vehicle.cpp)


#if (CMAKE_BUILD_TYPE MATCHES Debug)
#    add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/bin/debug")
#elseif(CMAKE_BUILD_TYPE MATCHES Release)
#    add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/bin/stable")
#endif()