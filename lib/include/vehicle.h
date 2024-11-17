#pragma once

#include <string>

enum class Type { GROUND = 1, AIR, GROUND_AIR };

class Vehicle {
	private:
		std::string name;
		double speed;
		Type type;
	protected:
		Vehicle(std::string, double, Type);
	public:
		virtual ~Vehicle() = default;
		const std::string& getName() const;
		double getSpeed() const;
		Type getType() const;
		virtual double getTotalTime(double) const = 0;
};