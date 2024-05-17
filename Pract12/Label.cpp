#include "Label.h"

void Label::print() const
{
	std::cout << "Label";
}

void Label::setDataDialog(MyString labelText) const
{
	this->labelText = labelText;
}
