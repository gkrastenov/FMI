// Task0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int recursion(double *arr, int startIndex, int sum = 1)
{
	if (startIndex <= (sizeof(arr) /sizeof(arr[0])))
	{
		return sum;
	}

	if (arr[startIndex] > 0 && arr[startIndex] > arr[startIndex-1])
	{
		return sum * arr[startIndex];
	}
	return recursion(arr, startIndex+1, sum);
}
int main()
{
    double arr[] = { 2.1, 0, 9.9, 3, 1, -1, 14.5, 7 };
	std::cout << recursion(arr, 1);
}