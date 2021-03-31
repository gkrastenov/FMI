#pragma once
#include "Room.h"
#include<iostream>
class Apartment
{
private:
	Room* rooms;
	int number;

	void setNumber(const int number);
	void setRooms(const Room* rooms, int const length);
public:
	Apartment();
	Apartment(const Apartment& apartment);
	~Apartment();

	Apartment& operator = (const Apartment& apartment);
	bool operator < (Apartment& apartment);
	bool operator <= (Apartment& apartment);
	bool operator == (Apartment& apartment);
	bool operator >= (Apartment& apartment);
	bool operator > (Apartment& apartment);

	Room& operator [] (const char* apartment);

	friend std::istream& operator>>(std::istream& is, Apartment& apartment);
	friend std::ostream& operator<<(std::ostream& os, const Apartment& apartment);

	Room* getRooms() const;
	int getNumber() const;

	double allArea();
	double averageArea();
};

