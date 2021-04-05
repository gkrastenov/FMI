#pragma once
#include "DateTime.h"
enum Unit
{
	Kilograms,
	Liters
};

class Product
{
private:
	char* description;
	DateTime expiryDate;
	DateTime entryDate;
	char* manufacturer;
	int quantity;
	int location;
	char* comment;
};
