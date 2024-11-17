#include <ground_vehicle.h>

GroundVehicle::GroundVehicle(std::string n, double s, double tus, double st) : Vehicle(n, s, Type::GROUND), timeUntilStop{ tus }, stopTime{ st } {}

double GroundVehicle::getTotalTime(double distance) const {
	double tt = distance / getSpeed();
	int stops = 0;
	if (timeUntilStop) {
		stops = tt / timeUntilStop;
		if (stops == tt / timeUntilStop) stops -= 1;
	}
	return tt + stops*stopTime;
}