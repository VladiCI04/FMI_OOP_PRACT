#pragma once
#include "Forms.h"
#include "String.h"
#include <iostream>

class Label : public Forms {
public:
	void print() const override;
	void setDataDialog(MyString labelText) const;

private:
	MyString labelText;
};