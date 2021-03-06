
#include <iostream>
using namespace std;

int const allMusicsLength = 3000;
int const oneMusicLength = 100;
int const numberOfMusics = 30;
int biggestMusicLength = 0;

void fun(char matrix[][oneMusicLength], int matrixIndex, int startIndex)
{
	if (matrix[matrixIndex][startIndex] == ';' || matrix[matrixIndex][startIndex] == '\0')
	{
		return;
	}
	cout << matrix[matrixIndex][startIndex];
	fun(matrix, matrixIndex, startIndex + 1);
}

void print(char arr[][oneMusicLength], int matrixCounter, int startIndex = 0)
{
	if (matrixCounter < 0 )
	{
		return;
	}
	fun(arr, matrixCounter, startIndex);
	cout << "\n";
	print(arr, matrixCounter - 1, startIndex);
}

int get(char matrix[][oneMusicLength], int length)
{
	int biggestLength = 0;
	int currentCounter = 0;
	int index = 0;
	for (int i = 0; i <= length; i++)
	{	
		for (int j = 0; j< oneMusicLength; j++)
		{
			if (matrix[i][j] == ';' || matrix[i][j] == '\0')
			{
				break;
			}
			currentCounter++;
		}

		if (currentCounter > biggestLength)
		{
			biggestLength = currentCounter;	
			index = i;
			biggestMusicLength = biggestLength;

		}
		currentCounter = 0;
	}

	return index;
}


// Swapping two elements
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

int partition(char arr[], int p, int r)
{
	int x = arr[r];
	int i = p - 1;

	for (int j = p; j <= r - 1; j++)
	{
		if (arr[j] <= x)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[r]);
	return (i + 1);
}

void quickSort(char arr[], int p, int r)
{
	if (p < r)
	{
		int q = partition(arr, p, r);
		quickSort(arr, p, q - 1);
		quickSort(arr, q + 1, r);
	}
}

int main()
{
	char music[allMusicsLength];

	cin.getline(music, allMusicsLength - 1);

	char matrix[numberOfMusics][oneMusicLength];
	int index = 0;

	int matrixCounter = 0;

	// add text in matrix
	for (int i = 0; i <= allMusicsLength; i++)
	{
		if (music[index] == '\0')
		{
			break;
		}
		for (int j = 0; j < allMusicsLength; j++)
		{
			if (music[index] == '\0')
			{
				matrix[i][j] = ';';
				break;
			}

			if (music[index] == ';')
			{
		
				matrix[i][j] = music[index];
				index++;
				break;
			}
			matrix[i][j] = music[index];
			index++;
		}
		matrixCounter++;
	}
	cout << '\n';
	print(matrix, matrixCounter - 1);
	
	int indexOfBiggestTittle = get(matrix, matrixCounter - 1);

	quickSort(matrix[indexOfBiggestTittle], 0, biggestMusicLength - 1);

	cout << '\n';
	for (int  i = 0; i < biggestMusicLength; i++)
	{
		if (matrix[indexOfBiggestTittle][i] == ';' || matrix[indexOfBiggestTittle][i] == '\0')
		{
			break;
		}
		if (matrix[indexOfBiggestTittle][i] == ' ' )
		{
			continue;
		}
		cout << matrix[indexOfBiggestTittle][i];
		/*
		* if ( (matrix[indexOfBiggestTittle][i] >= 48 || matrix[indexOfBiggestTittle][i] <= 57)  ||
			(matrix[indexOfBiggestTittle][i] >= 65 || matrix[indexOfBiggestTittle][i] <= 90)  ||
			(matrix[indexOfBiggestTittle][i] >= 97 || matrix[indexOfBiggestTittle][i] <= 112))
		{
			cout << matrix[indexOfBiggestTittle][i];
		}
		*/

		
	}
}
