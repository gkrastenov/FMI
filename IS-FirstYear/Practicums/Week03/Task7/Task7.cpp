// Task7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	int n;
	bool isPrime = true;

	cin >> n;

	if (n <= 1) {
		isPrime = false;
	}
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			isPrime = false;
		}
	}

	cout << boolalpha << isPrime;
}
