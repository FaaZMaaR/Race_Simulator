cmake_minimum_required(VERSION 3.22.0)

project(Race_Simulator)

set(CMAKE_BUILD_TYPE Release)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_HOME_DIRECTORY}/build)

add_subdirectory("lib")

add_executable(run_race_simulator main.cpp)

target_link_libraries(run_race_simulator race_simulator_lib)