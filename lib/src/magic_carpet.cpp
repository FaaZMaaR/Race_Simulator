#include <magic_carpet.h>

MagicCarpet::MagicCarpet() : AirVehicle("Ковер-самолет", 10, 0) {}

double MagicCarpet::getTotalTime(double distance) const {
	double drf = distanceReductionFactor;
	if (distance >= 1000 && distance < 5000) drf = 3;
	else if (distance >= 5000 && distance < 10000) drf = 10;
	else if (distance >= 10000) drf = 5;
	return distance * (1 - drf / 100) / getSpeed();
}