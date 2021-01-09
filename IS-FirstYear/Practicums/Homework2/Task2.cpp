#include <iostream>
using namespace std;

int main()
{
	const int MATRIX_ROW = 128;
	const int MATRIX_COL = 128;

	int n;
	cin >> n;

	int matrix[MATRIX_ROW][MATRIX_COL];

	int diagonalIndex = n - 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j == diagonalIndex)
			{
				matrix[i][j] = 1;
				continue;
			}
			if (j < diagonalIndex)
			{
				matrix[i][j] = 0;
				continue;
			}

			if (diagonalIndex < j)
			{
				matrix[i][j] = 2;
				continue;
			}
		}
		diagonalIndex--;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << matrix[i][j];
		}
		cout <<"\n";
	}
}
