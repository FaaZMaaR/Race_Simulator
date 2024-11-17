#include <camel.h>

Camel::Camel() : GroundVehicle("Верблюд", 10, 30, 8) {}

double Camel::getTotalTime(double distance) const{
	double tt = distance / getSpeed();
	int stops = 0;
	if (timeUntilStop) {
		stops = tt / timeUntilStop;
		if (stops == tt / timeUntilStop) stops -= 1;
	}
	double ts = 0;
	for (int i = 0; i < stops; i++) {
		if (i == 0) ts += 5;
		else ts += stopTime;
	}
	return tt + ts;
}