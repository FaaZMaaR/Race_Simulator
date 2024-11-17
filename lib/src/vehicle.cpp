#include <vehicle.h>

Vehicle::Vehicle(std::string n, double s, Type t) : name{ n }, speed{ s }, type{ t } {}

const std::string& Vehicle::getName() const {
	return name;
}

double Vehicle::getSpeed() const {
	return speed;
}

Type Vehicle::getType() const {
	return type;
}