#pragma once
#include "CarPart.h"

class Wheel : CarPart {
public:
	Wheel();
	Wheel(const char* manufacturerName, const char* description, const unsigned int width, const unsigned short profile, const unsigned short diameter);

	void setWidth(const unsigned int width);
	void setProfile(const unsigned short profile);
	void setDiameter(const unsigned short diameter);

private:
	unsigned int width = 0;
	unsigned short profile = 0;
	unsigned short diameter = 0;
};