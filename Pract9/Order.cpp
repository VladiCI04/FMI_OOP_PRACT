#include "Order.h"
#pragma warning (disable: 4996)

void Order::free() {
	delete[] restourantName;
	restourantName = nullptr;

	productsCount = 0;

	capacity = 2;


	delete[] productsList;
	productsList = nullptr;
}
void Order::copyFrom(const Order& other) {
	restourantName = new char[strlen(other.restourantName) + 1];
	strcpy(restourantName, other.restourantName);

	productsCount = other.productsCount;

	capacity = other.capacity;

	productsList = new String[other.capacity];
	for (unsigned int index = 0; index < other.productsCount; index++) {
		productsList[index] = other.productsList[index];
	}
}
void Order::moveFrom(Order&& other) {
	restourantName = other.restourantName;
	other.restourantName = nullptr;

	productsCount = other.productsCount;

	capacity = other.capacity;

	productsList = other.productsList;
	other.productsList = nullptr;
}

Order::Order() = default;
Order::Order(const char* restourantName, const unsigned int productsCount, const unsigned int capacity, String* productsList) : productsCount(productsCount), capacity(capacity) {
	setRestourantName(restourantName);
	setProductsList(productsList);
}
Order::Order(const Order& other) {
	if (this != &other) {
		copyFrom(other);
	}
}
Order::Order(Order&& other) noexcept {
	if (this != &other) {
		moveFrom(std::move(other));
	}
}
Order& Order::operator=(const Order& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}
Order& Order::operator=(Order&& other) noexcept {
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}

	return *this;
}
Order::~Order() {
	free();
}

const char* Order::getRestourantName() const {
	return restourantName;
}
void Order::setRestourantName(const char* restourantName) {
	strcpy(this->restourantName, restourantName);
}
const String* Order::getProductsList() const {
	return productsList;
}
void Order::setProductsList(String* productsList) {
	this->productsList = productsList;
}

void Order::addProduct(const String& product) {
	productsList[productsCount] = product;
	productsCount++;
}
unsigned int Order::timeForOrder() const {
	return 0;
}
