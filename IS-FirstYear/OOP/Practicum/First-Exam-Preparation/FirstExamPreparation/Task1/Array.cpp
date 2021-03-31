#include "Array.h"
#include<iostream>

Array::Array()
{
	this->capacity = 8;
	this->size = 0;
	this->elements = new int[capacity];
}
Array::~Array()
{
	this->capacity = 0;
	this->size = 0;
	delete[] elements;
	this->elements = nullptr;
}

void Array::add(int element)
{
	if (full())
	{
		resize();
		elements[size] = element;
	}
	else {
		elements[size] = element;
	}

	this->size++;
}
void Array::resize()
{
	this->capacity *= 2;
	int* newArray = new int[this->capacity];
	for (size_t i = 0; i < size; i++)
	{
		newArray[i] = elements[i];
	}
	delete[] elements;
	this->elements = newArray;
}
bool Array::full()
{
	if (capacity == size)
		return true;
	return false;
}

bool Array::contains(int element)
{
	for (size_t i = 0; i < size; i++)
	{
		if (elements[i] == element)
			return true;
	}
	return false;
}

bool Array::empty()
{
	if (count() == 0)
	{
		return true;
	}
	return false;
}

int Array::count()
{
	return this->size;
}

void Array::print()
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << "element[" << i << "] = " << elements[i] << std::endl;
	}
}