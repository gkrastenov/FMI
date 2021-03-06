#include <iostream>
using namespace std;

double func(double array[], int index, double sum, int maxSize)
{
	if (index + 1 == maxSize)
	{
		return sum;
	}
	if (array[index] > 0 && array[index] > array[index + 1])
	{
		sum += array[index];
	}

	return func(array, index + 1, sum, maxSize);
}
int main()
{
	cout << "Length: ";
	int n;
	cin >> n;
	double *array = new double[n];
	for (int i = 0; i < n; i++)
	{
		cin >> array[i];
	}

	cout << func(array, 0, 0, n);

	delete array;
}
