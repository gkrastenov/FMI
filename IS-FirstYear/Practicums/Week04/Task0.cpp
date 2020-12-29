// Task0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
	int n, sum = 0;
    cin >> n;
	for (int i = 0; i <= n;i++)
	{
		sum += i;
	}
	cout << "The sum is: " << sum << endl;
}
