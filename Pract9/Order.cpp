#include "Order.h"
#pragma warning (disable: 4996)

void Order::free() {
	delete[] this->restourantName;
	this->restourantName = nullptr;

	this->productsCount = 0;

	this->capacity = 2;

	delete[] this->productsList;
	this->productsList = nullptr;
}
void Order::copyFrom(const Order& other) {
	this->restourantName = new char[strlen(other.restourantName) + 1];
	strcpy(this->restourantName, other.restourantName);

	this->productsCount = other.productsCount;

	this->capacity = other.capacity;

	this->productsList = new String[other.capacity];
	for (unsigned int index = 0; index < other.productsCount; index++) {
		this->productsList[index] = other.productsList[index];
	}
}
void Order::moveFrom(Order&& other) {
	this->restourantName = other.restourantName;
	other.restourantName = nullptr;

	this->productsCount = other.productsCount;

	this->capacity = other.capacity;

	this->productsList = other.productsList;
	other.productsList = nullptr;
}

Order::Order() = default;

Order::Order(const char* restourantName, const unsigned int productsCount, const unsigned int capacity, const String* productsList) : productsCount(productsCount), capacity(capacity) {
	this->setRestourantName(restourantName);
	this->setProductsList(productsList);
}

Order::Order(const Order& other) {
	if (this != &other) {
		copyFrom(other);
	}
}

Order& Order::operator=(const Order& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}

Order::~Order() {
	free();
}

Order::Order(Order&& other) noexcept {

}

Order& Order::operator=(Order&& other) noexcept {
	
}

const char* Order::getRestourantName() const {
	return nullptr;
}

void Order::setRestourantName(const char* restourantName) {

}

const String* Order::getProductsList() const {
	return nullptr;
}

void Order::setProductsList(const String* productsList) {

}

void Order::addProduct(const String& product) {

}

unsigned int Order::timeForOrder() const {
	return 0;
}
