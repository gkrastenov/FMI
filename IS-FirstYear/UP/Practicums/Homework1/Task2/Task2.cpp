// Task2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    int number, currentNumber;
    cin >> number;

	bool flag = true;
	currentNumber = number;

	while (currentNumber != 1)
	{
		if (currentNumber % 2 == 1)
		{
			flag = false;
			break;
		}
		else {
			currentNumber = currentNumber / 2;
		}
	}

	int numerous = 0;
	int help = 1;
	if (flag)
	{
		if (number<3)
		{
			cout << numerous << endl;
		}

		do
		{
			help *= 3;
			numerous++;
			
		} while (help * 3 < number);
	}
	else {
		if (number < 5)
		{
			cout << numerous << endl;
		}

		do
		{
			help *= 5;
			numerous++;
		} while (help * 5 < number);
	}

	cout << numerous << endl;

}
