#include <iostream>
using namespace std;

void func(int *array, int n, int value)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				break;
			}

			if (array[i] + array[j] == value)
			{
				cout << "(" << i << "," << j << ")" << endl;
			}
		}
	}
}
int main()
{
	cout << "Length: ";
	int n, value;
	cin >> n;
	int* array = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}

	cout << "Value: " << endl;;
	cin >> value;

	func(array, n, value);
}
