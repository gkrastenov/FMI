// Task3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	const int size = 128;
	int arr[size];
    int n;
    cout << "N: " << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	double average = 0;
	bool flag = false;
	bool isEqual = false;
	for (int i = 0; i < n; i++)
	{
		 // arr[i+1]<0 -> negative number from array
		if (arr[i]<arr[i+1] || arr[i+1]<0)
		{
			if (arr[i]<10)
			{
				isEqual = true;
				flag = true;
				average += arr[i];
				continue;
			}
			// check for number
			int last = arr[i]%10;
			int first;
			
			int currentNumber = arr[i];
			while (currentNumber != 0)
			{
				first = currentNumber % 10;
				currentNumber = currentNumber / 10;
			}
			if (first == last)
			{
				isEqual = true;
			}
			else {
				isEqual = false;
				break;
			}
			flag = true;
			first = 0;
		}
		else {
			flag = false;
			break;
		}
		average += arr[i];
	}

	if (flag && isEqual)
	{
		cout << "Yes" << endl;
		cout << average / n << endl;
	}
	else {
		cout << "No" << endl;
	}
}