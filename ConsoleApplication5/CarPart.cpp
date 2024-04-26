#include "CarPart.h"

static unsigned int curId = 0;

CarPart::CarPart() = default; 
CarPart::CarPart(const char* manufacturerName, const char* description) {
	id = curId++;

	setManufacturerName(manufacturerName);

	setDescription(description);
}
CarPart::CarPart(const CarPart& other) {
	if (this != &other) {
		copyFrom(other);
	}
	else {
		throw std::invalid_argument("CarPart objects are same.");
	}
}
CarPart::CarPart(CarPart&& other) noexcept {
	if (this != &other) {
		moveFrom(std::move(other));
	}
	else {
		throw std::invalid_argument("CarPart objects are same.");
	}
}
CarPart CarPart::operator=(const CarPart& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}
	else {
		throw std::invalid_argument("CarPart objects are same.");
	}

	return *this;
}
CarPart CarPart::operator=(CarPart&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	else {
		throw std::invalid_argument("CarPart objects are same.");
	}

	return *this;
}
CarPart::~CarPart() {
	free();
}

void CarPart::setManufacturerName(const char* manufacturerName) {
	if (!manufacturerName) {
		this->manufacturerName = new char[strlen(manufacturerName)];
		strcpy(this->manufacturerName, manufacturerName);
	}
	else {
		throw std::invalid_argument("ManufacturerName is nullptr.");
	}
}

void CarPart::setDescription(const char* description) {
	if (!description) {
		this->description = new char[strlen(description)];
		strcpy(this->description, description);
	}
	else {
		throw std::invalid_argument("Description is nullptr.");
	}
}

void CarPart::free() {
	this->id = 0;

	delete[] this->manufacturerName;
	this->manufacturerName = nullptr;

	delete[] this->description;
	this->description = nullptr;
}
void CarPart::copyFrom(const CarPart& other) {
	this->id = other.id;

	this->manufacturerName = new char[strlen(other.manufacturerName)];
	strcpy(this->manufacturerName, other.manufacturerName);

	this->description = new char[strlen(other.description)];
	strcpy(this->description, other.description);
}
void CarPart::moveFrom(CarPart&& other) {
	this->id = other.id;
	other.id = 0;

	this->manufacturerName = other.manufacturerName;
	other.manufacturerName = nullptr;

	this->description = other.description;
	other.description = nullptr;
}