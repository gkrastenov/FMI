// Task9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j<i)
			{
				cout << '-';
			}

			if (i==j)
			{
				cout << '0';
			}

			if (j>i)
			{
				cout << '+';
			}
		}

		cout << endl;
	}
}

