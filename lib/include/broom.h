#pragma once

#include <air_vehicle.h>

class Broom : public AirVehicle {
public:
	Broom();
	double getTotalTime(double) const override;
};