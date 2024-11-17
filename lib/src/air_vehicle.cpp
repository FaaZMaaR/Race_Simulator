#include <air_vehicle.h>

AirVehicle::AirVehicle(std::string n, double s, double drf) : Vehicle(n, s, Type::AIR), distanceReductionFactor{ drf } {}

double AirVehicle::getTotalTime(double distance) const {
	return distance * (1 - distanceReductionFactor / 100) / getSpeed();
}