#include <speedster_camel.h>

SpeedsterCamel::SpeedsterCamel() : GroundVehicle("Верблюд-быстроход", 40, 10, 8) {}

double SpeedsterCamel::getTotalTime(double distance) const {
	double tt = distance / getSpeed();
	int stops = 0;
	if (timeUntilStop) {
		stops = tt / timeUntilStop;
		if (stops == tt / timeUntilStop) stops -= 1;
	}
	double ts = 0;
	for (int i = 0; i < stops; i++) {
		if (i == 0) ts += 5;
		else if (i == 1) ts += 6.5;
		else ts += stopTime;
	}
	return tt + ts;
}