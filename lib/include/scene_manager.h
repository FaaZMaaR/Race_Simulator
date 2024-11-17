#pragma once

#include <iostream>

#include <camel.h>
#include <speedster_camel.h>
#include <centaur.h>
#include <rover_boots.h>
#include <magic_carpet.h>
#include <eagle.h>
#include <broom.h>
#include <race.h>

enum class Scene { PICK_RACE, DEFINE_DISTANCE, REG_VEHICLE_OR_START_RACE, PICK_VEHICLE, RACE_RESULTS, RACE_AGAIN, EXIT };
enum class VehicleType { NONE, CAMEL, SPEEDSTER_CAMEL, CENTAUR, ROVER_BOOTS, MAGIC_CARPET, EAGLE, BROOM };

class SceneManager {
	private:
		Scene scene;
		Type raceType;
		Race* race;
		RaceResult* raceResults;
		void fillRaceResults();
		bool checkVehicle(const Vehicle&);
		bool checkRaceType(const Vehicle&);
		void pickRaceType();
		void createRace();
		void registerOrStart();
		void pickVehicle();
		void showResults();
		void raceAgain();
	public:
		SceneManager();
		~SceneManager();
		Scene getScene() const;
		void playScene();
};