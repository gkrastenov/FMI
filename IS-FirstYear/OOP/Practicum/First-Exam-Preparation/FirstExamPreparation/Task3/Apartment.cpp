#include "Apartment.h"

Apartment::Apartment()
{
	this->rooms = nullptr;
	this->number = 0;
}
Apartment::Apartment(const Apartment& apartment)
{
	setRooms(apartment.rooms, apartment.number);
	setNumber(apartment.number);
}
Apartment::~Apartment()
{
	delete[] this->rooms;
	this->rooms = nullptr;
	this->number = 0;
}
Apartment& Apartment::operator = (const Apartment& apartment)
{
	if (this != &apartment)
	{
		delete[] this->rooms;
		setRooms(apartment.rooms, apartment.number);
		setNumber(apartment.number);
	}

	return *this;
}
void Apartment::setNumber(const int number)
{
	this->number = number;
}
void Apartment::setRooms(const Room* rooms, const int length)
{
	delete[] this->rooms;
	this->rooms = new Room[length];
	for (size_t i = 0; i < length; i++)
	{
		this->rooms[i] = rooms[i];
	}
}
Room* Apartment::getRooms() const
{
	return this->rooms;
}
int Apartment::getNumber() const
{
	return this->number;
}
std::ostream& operator<<(std::ostream& os, const Apartment& apartment)
{
	//Room* rooms;
	//int number;
	std::cout << "Apartament description:"<< std::endl;

	std::cout << "Number of rooms :" << apartment.number << std::endl;
	std::cout << "All rooms: " << std::endl;
	for (size_t i = 0; i < apartment.number; i++)
	{
		std::cout << "room[" << i <<"] "<< std::endl;
		os << apartment.rooms[i];
	}

	return os;
}
std::istream& operator>>(std::istream& is, Apartment& apartment)
{
	delete[] apartment.rooms;
	apartment.number = 0;

	std::cout << "Number of Rooms" << std::endl;
	is >> apartment.number;

	apartment.rooms = new Room[apartment.number];
	for (size_t i = 0; i < apartment.number; i++)
	{
		Room currRoom = Room();
		is >> currRoom;
		apartment.rooms[i] = currRoom;
	}

	return is;
}
double Apartment::allArea()
{
	double sum = 0;
	for (size_t i = 0; i < this->number; i++)
	{
		sum += this->rooms[i].getArea();
	}
	return sum;
}
double Apartment::averageArea() 
{
	return this->allArea() / this->number;
}

bool Apartment::operator<(Apartment& apartment)
{
	if (this->averageArea() < apartment.averageArea())
		return true;
	return false;
}
bool Apartment::operator<=(Apartment& apartment)
{
	if (this->averageArea() <= apartment.averageArea())
		return true;
	return false;
}
bool Apartment::operator==(Apartment& apartment)
{
	if (this->averageArea() == apartment.averageArea())
		return true;
	return false;
}
bool Apartment::operator>(Apartment& apartment)
{
	if (this->averageArea() > apartment.averageArea())
		return true;
	return false;
}
bool Apartment::operator>=(Apartment& apartment)
{
	if (this->averageArea() >= apartment.averageArea())
		return true;
	return false;
}
// If can not find room will return empty room.
Room& Apartment::operator[](const char* description)
{
	for (size_t i = 0; i < this->number; i++)
	{
		if ( strcmp(this->rooms[i].getDescription(), description) == 0)
		{
			return this->rooms[i];
		}
	}
	std::cout << "It was not found room with this description" << std::endl;
	// will return empty room
	Room room = Room();
	return room;
}
