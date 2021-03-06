// Task1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "a" << i << " = " << i * i + 3 * i << endl;
	}
}
