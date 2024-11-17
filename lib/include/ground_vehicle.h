#pragma once

#include <vehicle.h>

class GroundVehicle : public Vehicle {
	protected:
		double timeUntilStop;
		double stopTime;
	public:
		GroundVehicle(std::string, double, double, double);
		double getTotalTime(double) const override;
};