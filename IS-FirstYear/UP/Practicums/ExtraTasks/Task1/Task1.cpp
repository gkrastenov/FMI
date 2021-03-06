// Task1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

char* concat(char* first, char* second, int firstLen, int secondLen)
{
	char* newArr = new char[firstLen + secondLen];
	for (int i = 0; i < firstLen; i++)
	{
		newArr[i] = first[i];
	}
	for (int i = firstLen; i < secondLen; i++)
	{
		newArr[i] = second[i];
	}

	return newArr;
}
int main()
{
  
}