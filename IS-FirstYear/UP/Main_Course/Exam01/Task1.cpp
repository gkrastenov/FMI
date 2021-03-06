// Task1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

/// <summary>
/// Exercise 1. A)
/// </summary>
int main()
{
	int carrot;
	// маруля
	int lettuce;
	int cucumbers;
	int peppers;
	int tomatoes;

	bool isMercurey;
	bool isHealthy;
	if (carrot == 2 && cucumbers == 2 
		&& lettuce == 1 && peppers == 3  
		||
		carrot == 1 && cucumbers == 1 
		&& peppers == 1 && tomatoes == 2)
	{
		isHealthy = true;
	}
	else {
		isHealthy = false;
	}


	if (isHealthy && isMercurey)
	{
		cout << boolalpha << true;
	}
	else {
		cout << boolalpha << false;
	}
}
