#pragma once
#include "DateTime.h"
enum Unit
{
	Kilograms,
	Liters,
	Unknown
};

class Product
{
private:
	char* description;
	DateTime expiryDate;
	DateTime entryDate;
	char* manufacturer;
	Unit unit;
	int quantity;
	int location;
	char* comment;
};
