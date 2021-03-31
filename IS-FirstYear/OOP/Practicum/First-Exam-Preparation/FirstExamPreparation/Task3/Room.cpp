#include "Room.h"
#include<iostream>

Room::Room()
{
	this-> area = 0;
	this-> description = nullptr;
}
Room::Room(const Room& room)
{
	setArea(room.area);
	setDescription(room.description);
}
Room::~Room()
{
	this->area = 0;
	delete[] description;
	this->description = nullptr;
}
Room& Room::operator=(const Room& room)
{
	if (this != &room)
	{
		this->area = 0;
		delete[] description;

		setArea(room.area);
		setDescription(room.description);
	}
	return *this;
}
void Room::setDescription(const char* description)
{
	if (description == nullptr)
	{
		delete[] description;
		this->description = nullptr;
		return;
	}

	if (compareSize(description))
	{
		size_t lengthDescription = strlen(description) + 1;
		this->description = new char[lengthDescription];
		strcpy_s(this->description, lengthDescription, description);
	}
	else {
		printInvalidInputMessage();
	}

}
void Room::setArea(const double area)
{
	this->area = area;
}
bool Room::compareSize(const char* array)
{
	size_t currentSize = strlen(array) + 1;
	if (currentSize > this->MAX_SIZE_DESCRIPTION)
		return false;

	return true;
}
void Room::printInvalidInputMessage()
{
	std::cout << "Invalid input" << std::endl;
}

double Room::getArea() const
{
	return this->area;
}
char* Room::getDescription() const
{
	return this->description;
}
std::ostream& operator<<(std::ostream& os, const Room& room)
{
	std::cout << "Area: " << std::endl;
	os << room.area << std::endl;
	std::cout << "Description: " << std::endl;
	os << room.description << std::endl;

	return os;
}

std::istream& operator>>(std::istream& is, Room& room)
{
	delete[] room.description;
	room.area = 0;

	std::cout << "Area: " << std::endl;
	is >> room.area;
	std::cout << "Description with maximum size " << room.MAX_SIZE_DESCRIPTION <<std::endl;

	char* newDescription = new char[room.MAX_SIZE_DESCRIPTION];
	is.ignore();
	is.getline(newDescription, room.MAX_SIZE_DESCRIPTION);
	int len = strlen(newDescription) + 1;
	room.description = new char[len];
	strcpy_s(room.description, len, newDescription);

	return is;
}