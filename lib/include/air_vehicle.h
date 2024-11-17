#pragma once

#include <vehicle.h>

class AirVehicle : public Vehicle {
protected:
	double distanceReductionFactor;
public:
	AirVehicle(std::string, double, double);
	double getTotalTime(double) const override;
};