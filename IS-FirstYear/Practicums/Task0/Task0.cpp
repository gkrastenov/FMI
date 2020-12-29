// Task0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;




int main()
{
	int matrix[4][4];

	int index = 0;
	int number = 1;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i == index && j == index)
			{
				index++;
				matrix[i][j] = 1;
				number += 1;
				continue;
			}
			matrix[i][j] = number;
			number++;
		}
	}
	
	// print
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << matrix[i][j]<<" ";
		}
		cout << endl;
	}
}