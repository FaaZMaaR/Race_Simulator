#include <broom.h>

Broom::Broom() : AirVehicle("Метла", 20, 0) {}

double Broom::getTotalTime(double distance) const {
	double drf = static_cast<int>(distance/1000);
	return distance * (1 - drf / 100) / getSpeed();
}