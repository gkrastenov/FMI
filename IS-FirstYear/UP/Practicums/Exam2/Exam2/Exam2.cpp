
#include <iostream>
using namespace std;

int const allMusicsLength = 1000;
void print(char arr[][500], int matrixCounter)
{
	if (matrixCounter < 0 )
	{
		return;
	}
	for (int i = 0; i < 500; i++)
	{
		if (arr[matrixCounter][i] == ';' || arr[matrixCounter][i] == '\0')
		{
			break;
		}
		cout << arr[matrixCounter][i];	
	}
	print(arr, matrixCounter--);
}

// Du hast - Rammstein; Wind of change - Scorpions; Az iskam - Revoluciq Z; Hipnoza - Divna; Habibi- Ìohombi Costi Shaggy Faydee; Can't let you go - Rainbow; Dneven red - RDMK; Cvete moe - Ku ku band
int main()
{
	char music[allMusicsLength];

	cin.getline(music, allMusicsLength - 1);

	char matrix[10][500];
	int index = 0;

	int matrixCounter = 0;

	// add text in matrix
	for (int i = 0; i < allMusicsLength; i++)
	{
		if (music[index] == '\0')
		{
			break;
		}
		for (int j = 0; j < allMusicsLength; j++)
		{
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
	;
	print(matrix, matrixCounter - 1);
	
}
