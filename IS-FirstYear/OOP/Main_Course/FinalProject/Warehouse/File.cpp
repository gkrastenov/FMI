#include<iostream>
#include <fstream>

#include "File.h"
File::File()
{
	this->name = nullptr;
	this->isOpen = false;
}

File::File(const char* name)
{
	// TODO: check for valid name

	size_t nameSize = strlen(name) + 1;
	this->name = new char[nameSize];
	strcpy_s(this->name, nameSize, name);
	this->isOpen = false;
}

File::~File()
{
	delete[] this->name;
	this->name = nullptr;
	this->isOpen = false;
}

void File::create()
{
	// TODO: check for valid name
	// TODO: check if exist file with this name
	std::ofstream File(this->name);
}