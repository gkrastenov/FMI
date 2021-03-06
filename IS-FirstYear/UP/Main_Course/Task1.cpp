#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

void putDiagonal(double matrix[][MAX_SIZE], double* arr, int len)
{
	int index = 0;
	for (int i = 0; i < len; i++)
	{
		matrix[index][index] = arr[i];
		index++;
	}
}

void putDownNumber(double matrix[][MAX_SIZE], int len)
{
	int diagonalIndex = 0;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			if (i == diagonalIndex && j == diagonalIndex)
			{
				diagonalIndex++;
				break;
			}
			matrix[i][j] = i + matrix[i - 1][j];
		}
	}
}

void putUpperNumber(double matrix[][MAX_SIZE], int len)
{
	int diagonalIndex = len - 2;
	for (int i = len - 2; i >= 0; i--)
	{
		for (int j = diagonalIndex+1; j<=len; j++)
		{
			if (j == len)
			{
				diagonalIndex--;
				break;
			}
			matrix[i][j] = (matrix[i][j-1] + matrix[i+1][j])/2;
		}
	}
}

int main()
{
	int n;
	cout << "N: ";
	cin >> n;

	double diagonal[MAX_SIZE];
	int len = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> diagonal[i];
		len++;
	}

	double matrix[MAX_SIZE][MAX_SIZE];
	putDiagonal(matrix, diagonal, len);
	putDownNumber(matrix, len);
	putUpperNumber(matrix, len);

	// print matrix
	cout << "\n";
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
}
