#pragma once

class Vector {
private: 
	unsigned int capacity = 2;
	int* vector = nullptr;
	unsigned int size = 0;
	void copyFrom(const Vector other);
	void free();

public:
	Vector() = default;
	Vector(const unsigned int capacity);
	Vector(const Vector& other);
	Vector& operator= (const Vector& other);
	~Vector();

	unsigned int getSize() const;
	void setSize(const unsigned int size);
	int* getVector() const;
	void setVector(int* vector);

	void resizeUpSize();
	void resizeDownSize();
	void push_back(const int element);
	void pop_back();
	void insert(const unsigned int index, const int element);
	void erase(const unsigned int index, const int element);
};