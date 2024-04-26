#include "Wheel.h"

Wheel::Wheel() = default;
Wheel::Wheel(const char* manufacturerName, const char* description, const unsigned int width, const unsigned short profile, const unsigned short diameter) : CarPart(manufacturerName, description) {
	setWidth(width);
	setProfile(profile);
	setDiameter(diameter);
}

void Wheel::setWidth(const unsigned int width) {
	if (width >= 155 && width <= 365) {
		this->width = width;
	}
	else {
		throw std::out_of_range("Width is out of range.");
	}
}
void Wheel::setProfile(const unsigned short profile) {
	if (profile >= 30 && profile <= 80) {
		this->profile = profile;
	}
	else {
		throw std::out_of_range("Profile is out of range.");
	}
}
void Wheel::setDiameter(const unsigned short diameter) {
	if (diameter >= 13 && diameter <= 21) {
		this->diameter = diameter;
	}
	else {
		throw std::out_of_range("Diameter is out of range.");
	}
}