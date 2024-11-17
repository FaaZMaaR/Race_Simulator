#pragma once

#include <string>

#include <vehicle.h>

class Race {
	private:
		std::string name;
		Type type;
		double distance;
		int vehiclesCount;
		Vehicle** vehicles;
	public:
		Race(Type, double);
		~Race();
		const std::string& getName() const;
		Type getType() const;
		double getDistance() const;
		int getVehiclesCount() const;
		void addVehicle(Vehicle*);
		Vehicle& operator[](int) const;
};

struct RaceResult {
	std::string vehicleName;
	double totalTime;
};