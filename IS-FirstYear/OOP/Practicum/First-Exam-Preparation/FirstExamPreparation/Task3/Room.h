#pragma once
#include<iostream>
class Room
{
private:
	const int MAX_SIZE_DESCRIPTION = 30;
	double area;
	char* description;

	// if size of array is smaller then MAX_SIZE_DESCRIPTION will return true.
	bool compareSize(const char* array);
	void printInvalidInputMessage();
public:
	Room();
	Room(const Room& room);
	~Room();

	Room& operator = (const Room& room);
	
	friend std::istream& operator>>(std::istream& is, Room& room);
	friend std::ostream& operator<<(std::ostream& os, const Room& room);

	void setDescription(const char* description);
	void setArea(const double area);

	double getArea() const;
	char* getDescription() const;
};

