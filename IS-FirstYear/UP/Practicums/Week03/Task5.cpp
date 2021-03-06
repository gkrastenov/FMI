// Task5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	int n,sum=0;
	cin >> n;

	do
	{
		sum += n % 10;
		n = n / 10;
	} while (n!=0);


	cout << "The sum is: " << sum;
}