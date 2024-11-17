cmake_minimum_required(VERSION 3.22.0)

project(Race_Simulator_Lib)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set(LIBRARY_OUTPUT_PATH ${CMAKE_HOME_DIRECTORY}/build)

file(GLOB lib_src "include/*.h" "src/*.cpp")

add_library(race_simulator_lib SHARED ${lib_src})

target_include_directories(race_simulator_lib PUBLIC "include")