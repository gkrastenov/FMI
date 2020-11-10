// Task1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	long result = 1;
	for (int i = a; i <= b; i++)
	{
		result *= i;
	}
	cout << "The reuslt is: " << result << endl;
}
