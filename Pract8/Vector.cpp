#include "Vector.h"
#include <iostream>

void Vector::copyFrom(const Vector other) {
	this->capacity = other.capacity;
	this->size = other.size;
	this->vector = other.vector;
}
void Vector::free() {
	delete[] this->vector;
}

Vector::Vector() = default;
Vector::Vector(const unsigned int capacity) {
	this->capacity = capacity;
}
Vector::Vector(const Vector& other) {
	copyFrom(other);
}
Vector& Vector::operator= (const Vector& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}
Vector::~Vector() {
	free();
}

unsigned int Vector::getSize() const {
	return this->size;
}
void Vector::setSize(const unsigned int size) {
	this->size = size;
}
int* Vector::getVector() const {
	return this->vector;
}
void Vector::setVector(int* vector) {
	if (vector) {
		this->vector = vector;
	}
	else {
		throw std::exception("Not null pointer!");
	}
}

void Vector::resizeUpSize() {
	if (this->capacity == this->size) {
		this->capacity += 4;
	}
}
void Vector::resizeDownSize() {
	if (this->size == this->capacity / 4) {
		this->capacity -= 4;
	}
}
void Vector::push_back(const int element) {
	resizeUpSize();
	this->vector[size] = element;
	this->size++;
}
void Vector::pop_back() {
	if (this->size > 0) {
		this->size--;
		resizeDownSize();
	}
	else {
		throw std::out_of_range("Index is out of range!");
	}
}
void Vector::insert(const unsigned int index, const int element) {
	if (index < size) {
		for (unsigned int i = size; i > index; i--) {
			vector[i + 1] = vector[i];
		}
		vector[index] = element;
		size++;
		resizeUpSize();
	}
	else {
		throw std::out_of_range("Index is out of range!");
	}
}
void Vector::erase(const unsigned int index, const int element) {
	for (unsigned int i = index; i < size; i++) {

	}
}