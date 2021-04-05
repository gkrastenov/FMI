#pragma once
class DateTime
{
private:
	// seconds of minutes from 0 to 59
	const unsigned int MAX_SECONDS = 59;
	const unsigned int MIN_SECONDS = 0;
	//minutes of hour from 0 to 59
	const unsigned int MAX_MINUTES = 59;
	const unsigned int MIN_MINUTES = 0;	
	// hours of day from 0 to 24
	const unsigned int MAX_HOURS = 24;
	const unsigned int MIN_HOURS = 0;
	// day of month from 1 to 31
	const unsigned int MAX_DAY = 31;
	const unsigned int MIN_DAY = 0;
	// month of year from 0 to 12
	const unsigned int MAX_MONTH = 12;
	const unsigned int MIN_MONTH = 0;
	// year since 1900
	const unsigned int MIN_YEAR = 1900;

	unsigned int seconds;
	unsigned int minutes; 
	unsigned int hours; 
	unsigned int day; 
	unsigned int month; 
	unsigned int year;  
};

