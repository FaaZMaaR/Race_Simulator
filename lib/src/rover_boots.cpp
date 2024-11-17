#include <rover_boots.h>

RoverBoots::RoverBoots() : GroundVehicle("Ботинки-вездеходы", 6, 60, 5) {}

double RoverBoots::getTotalTime(double distance) const {
	double tt = distance / getSpeed();
	int stops = tt / timeUntilStop;
	if (stops == tt / timeUntilStop) stops -= 1;
	double ts = 0;
	for (int i = 0; i < stops; i++) {
		if (i == 0) ts += 10;
		else ts += stopTime;
	}
	return tt + ts;
}