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

public:
	const int MAX_DESCRIPTION_LENGTH = 150;
	const int MAX_MANUFACTURER_LENGTH = 50;
	const int MAX_COMMENT_LENGTH = 300;

	Product();
	~Product();

	void setDescription(const char* description);
	void setManufacturer(const char* manufacturer);
	void setExpiryDate(const char* expiryDate);
	void setEntryDate(const char* entryDate);
	void setQuantity(const int quantity);
	void setLocation(const int location);
	void setComment(const char* comment);
	

	char* getDescription();
	char* getManufacturer();
	void getExpiryDate();
	void getEntryDate();
	int getQuantity();
	int getLocation();
	char* getComment();
};
