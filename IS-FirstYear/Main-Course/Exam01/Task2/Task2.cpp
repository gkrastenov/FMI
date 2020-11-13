// Task2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
	int n;
	cout << "Money: ";
	cin >> n;
	int result = 0;
	do
	{
		if (n % 2 == 0)
		{
			n = n / 2;
		}
		else {
			n = n * 3 + 1;
		}
		result++;
	} while (n != 1);
	cout << "The result is: " << result << endl;
}
