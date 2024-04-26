#include "Acumulator.h"

Acumulator::Acumulator() = default;
Acumulator::Acumulator(const char* manufacturerName, const char* description, const int capacity, const char* bateryId) : CarPart(manufacturerName, description), capacity(capacity) {
	setBatteryId(bateryId);
}
Acumulator::Acumulator(const Acumulator& other) : CarPart(other) {
	if (this != &other) {
		copyFrom(other);
	}

	throw std::invalid_argument("Acumulator objects are same.");
}
Acumulator::Acumulator(Acumulator&& other) noexcept : CarPart(other) {
	if (this != &other) {
		copyFrom(other);
	}

	throw std::invalid_argument("Acumulator objects are same.");
}
Acumulator Acumulator::operator=(const Acumulator& other) {
	if (this != &other) {
		CarPart::operator=(other);
		free();
		copyFrom(other);
	}

	return *this;
}
Acumulator Acumulator::operator=(Acumulator&& other) noexcept {
	if (this != &other) {
		CarPart::operator=(std::move(other));
		free();
		moveFrom(std::move(other));
	}

	return *this;
}
Acumulator::~Acumulator() {
	free();
}

void Acumulator::setBatteryId(const char* batteryId) {
	if (!batteryId) {
		this->batteryId = new char[strlen(batteryId)];
		strcpy(this->batteryId, batteryId);
	}

	throw std::invalid_argument("batteryId is nullptr.");
}

void Acumulator::free() {
	this->capacity = 0;

	delete[] this->batteryId;
	this->batteryId = nullptr;
}
void Acumulator::copyFrom(const Acumulator& other) {
	this->capacity = capacity;

	this->batteryId = new char[strlen(batteryId)];
	strcpy(this->batteryId, batteryId);
}
void Acumulator::moveFrom(Acumulator&& other) {
	this->capacity = other.capacity;

	this->batteryId = other.batteryId;
}