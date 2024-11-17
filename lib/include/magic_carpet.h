#pragma once

#include <air_vehicle.h>

class MagicCarpet : public AirVehicle {
public:
	MagicCarpet();
	double getTotalTime(double) const override;
};