#pragma once

#include <ground_vehicle.h>

class Camel : public GroundVehicle {
	public:
		Camel();
		double getTotalTime(double) const override;
};