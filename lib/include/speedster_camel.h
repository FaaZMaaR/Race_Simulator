#pragma once

#include <ground_vehicle.h>

class SpeedsterCamel : public GroundVehicle {
public:
	SpeedsterCamel();
	double getTotalTime(double) const override;
};