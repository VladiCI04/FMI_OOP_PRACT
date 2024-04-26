#pragma once
#include <iostream>

class CarPart { 
public:
	CarPart();
	CarPart(const char* manufacturerName, const char* description);
	CarPart(const CarPart& other);
	CarPart(CarPart&& other) noexcept;
	CarPart operator=(const CarPart& other);
	CarPart operator=(CarPart&& other) noexcept;
	~CarPart();

	void setManufacturerName(const char* manufacturerName);
	void setDescription(const char* description);

private:
	unsigned int id = 0;
	char* manufacturerName = nullptr;
	char* description = nullptr;

	void free();
	void copyFrom(const CarPart& other);
	void moveFrom(CarPart&& other);
};