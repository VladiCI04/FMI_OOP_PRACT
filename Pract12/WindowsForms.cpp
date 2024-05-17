#include "WindowsForms.h"

WindowsForms::WindowsForms()
{

}

WindowsForms::WindowsForms(const WindowsForms** forms, const unsigned int capacity, unsigned int size)
{

}

WindowsForms::WindowsForms(const WindowsForms& other)
{

}

WindowsForms::WindowsForms(WindowsForms&& other)
{

}

WindowsForms& WindowsForms::operator=(const WindowsForms& other)
{
	// TODO: insert return statement here
}

WindowsForms& WindowsForms::operator=(WindowsForms&& other)
{
	// TODO: insert return statement here
}

WindowsForms::~WindowsForms()
{

}

void WindowsForms::addLabel()
{

}

void WindowsForms::addCheckBox()
{

}

void WindowsForms::addRadioButton()
{

}

void WindowsForms::copyFrom(const WindowsForms& other)
{
	forms = new Forms[other.capacity];
}

void WindowsForms::moveFrom(WindowsForms&& other)
{

}

void WindowsForms::free()
{

}
