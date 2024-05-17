#pragma once
#include "Forms.h"
#include "Label.h"
#include "CheckBox.h"
#include "RadioButton.h"

class WindowsForms {
public:
	WindowsForms();
	WindowsForms(const WindowsForms** forms, const unsigned int capacity, unsigned int size);
	WindowsForms(const WindowsForms& other);
	WindowsForms(WindowsForms&& other);
	WindowsForms& operator=(const WindowsForms& other);
	WindowsForms& operator=(WindowsForms&& other);
	~WindowsForms();

	void addLabel();
	void addCheckBox();
	void addRadioButton();

private:
	Forms** forms = nullptr;
	unsigned int capacity = 0;
	unsigned int size = 0;

	void copyFrom(const WindowsForms& other);
	void moveFrom(WindowsForms&& other);
	void free();
};