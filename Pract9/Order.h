#pragma once
#include "Order.h"
#include "String.h"

class Order {
private:
	char* restourantName = nullptr;
	unsigned int productsCount = 0;
	unsigned int capacity = 2;
	String* productsList = nullptr; 

	void free();
	void copyFrom(const Order& other);
	void moveFrom(Order&& other);

public:
	Order();
	Order(const char* restourantName, const unsigned int productsCount, const unsigned int capacity, String* productsList);
	Order(const Order& other);
	Order(Order&& other) noexcept;
	Order& operator=(const Order& other);
	Order& operator=(Order&& other) noexcept;
	~Order() noexcept;

	const char* getRestourantName() const;
	void setRestourantName(const char* restourantName);
	const String* getProductsList() const;
	void setProductsList(String* productsList);

	void addProduct(const String& product);
	unsigned int timeForOrder() const;
};