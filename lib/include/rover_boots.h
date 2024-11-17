#pragma once

#include <ground_vehicle.h>

class RoverBoots : public GroundVehicle {
public:
	RoverBoots();
	double getTotalTime(double) const override;
};