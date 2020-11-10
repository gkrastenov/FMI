// Task6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	int arrSize, br = 0;
	cin >> arrSize;
	
	char symbol;
	cin >> symbol;

	const int size = 128;
	char arr[size];
	for (int i = 0; i < arrSize; i++)
	{
		char input;
		cin >> input;
		if (input == symbol)
		{
			arr[i] = '*';
			br++;
		}
		else
		{
			arr[i] = input;
		}
	}

	cout << "The result is: " << br << endl;
}