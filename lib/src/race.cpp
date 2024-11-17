#include <race.h>

Race::Race(Type t, double d) : type{ t }, distance{ d }, vehiclesCount{ 0 }, vehicles{} {
	switch (type) {
		case Type::GROUND:
			name = "Гонка для наземного транспорта";
			break;
		case Type::AIR:
			name = "Гонка для воздушного транспорта";
			break;
		case Type::GROUND_AIR:
			name = "Гонка для наземного и воздушного транспорта";
			break;
	}
}

Race::~Race() {
	for (int i = 0; i < vehiclesCount; i++) {
		delete vehicles[i];
	}
	delete[] vehicles;
}

std::string Race::getName() const {
	return name;
}

Type Race::getType() const {
	return type;
}

double Race::getDistance() const {
	return distance;
}

int Race::getVehiclesCount() const {
	return vehiclesCount;
}

void Race::addVehicle(Vehicle* v) {
	Vehicle** tmp = new Vehicle* [vehiclesCount + 1];
	for (int i = 0; i < vehiclesCount; i++) {
		tmp[i] = vehicles[i];
	}
	delete[] vehicles;
	tmp[vehiclesCount++] = v;	
	vehicles = tmp;
}

Vehicle& Race::operator[](int i) const {
	return *vehicles[i];
}