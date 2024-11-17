cmake_minimum_required(VERSION 3.22.0)

project(Race_Simulator_Lib)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

set(LIBRARY_OUTPUT_PATH ${CMAKE_HOME_DIRECTORY}/build)

add_library(race_simulator_lib SHARED
	"include/vehicle.h"
	"include/ground_vehicle.h"
	"include/air_vehicle.h"
	"include/camel.h"
	"include/speedster_camel.h"
	"include/centaur.h"
	"include/rover_boots.h"
	"include/magic_carpet.h"
	"include/eagle.h"
	"include/broom.h"
	"include/race.h"
	"include/scene_manager.h"
	
	"src/vehicle.cpp"
	"src/ground_vehicle.cpp"
	"src/air_vehicle.cpp"
	"src/camel.cpp"
	"src/speedster_camel.cpp"
	"src/centaur.cpp"
	"src/rover_boots.cpp"
	"src/magic_carpet.cpp"
	"src/eagle.cpp"
	"src/broom.cpp"
	"src/race.cpp"
	"src/scene_manager.cpp"
)

target_include_directories(race_simulator_lib PUBLIC "include")