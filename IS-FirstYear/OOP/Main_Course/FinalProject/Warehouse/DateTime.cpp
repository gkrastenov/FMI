#include "DateTime.h"
#include<iostream>

using namespace std;
DateTime::DateTime()
{
    day = 0;
	month = 0;
	year = 0;
}
DateTime::DateTime(const int* date)
{
	day = date[0];
	month = date[1];
	year = date[2];

}

DateTime::~DateTime()
{
	day = 0;
	month = 0;
	year = 0;
}

int DateTime::getDay()
{
	return day;
}

int DateTime::getMonth()
{
	return month;
}

int DateTime::getYear()
{
	return year;
}

DateTime& DateTime::operator = (const DateTime& dateTime) {
    if (this != &dateTime)
    {
		this->year = dateTime.year;
		this->month = dateTime.month;
		this->day = dateTime.day;
    }
    return *this;
}