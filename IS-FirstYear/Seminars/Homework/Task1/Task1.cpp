#include <iostream>
using namespace std;

// Complexity : O(n) where n is number of elements.
bool isPalindromRecursion(char *arr, int startIndex, int endIndex)
{
	if (startIndex >= endIndex)
	{
		return true;
	}

	if (arr[startIndex] == arr[endIndex])
	{
		return isPalindromRecursion(arr, startIndex + 1, endIndex - 1);
	}
	else {
		return false;
	}
}

// Complexity : O(n/2) where n is number of elements.
bool isPalindromIterative(char* arr, int startIndex, int endIndex)
{
	while (startIndex < endIndex)
	{
		if (arr[startIndex] != arr[endIndex])
		{
			return false;
		}
		startIndex ++;
		endIndex --;
	}

	return true;
}

int main()
{
	cout << "Length of array: ";

	int len;
	cin >> len;

	if (len <= 0 )
	{
		cout << "Incorrect input\n";
		return 0;
	}

	char* array = new char[len];

	// console input
	for (int i = 0; i < len; i++)
	{
		cin >> array[i];
	}

	// len - 1 is last index in array
	cout << boolalpha << isPalindromRecursion(array, 0, len - 1) << "\n";
	cout << boolalpha << isPalindromIterative(array, 0, len - 1);

	delete[] array;
}
// Iterative method is faster than recursion method.