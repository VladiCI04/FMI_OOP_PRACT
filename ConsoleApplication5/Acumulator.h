#pragma once
#include "CarPart.h"

class Acumulator : CarPart {
public:
	Acumulator();
	Acumulator(const char* manufacturerName, const char* description, const int capacity, const char* bateryId);
	Acumulator(const Acumulator& other);
	Acumulator(Acumulator&& other) noexcept;
	Acumulator operator=(const Acumulator& other);
	Acumulator operator=(Acumulator&& other) noexcept;
	~Acumulator();

	void setBatteryId(const char* batteryId);

private:
	unsigned int capacity = 0;
	char* batteryId = nullptr;

	void free();
	void copyFrom(const Acumulator& other);
	void moveFrom(Acumulator&& other);
};