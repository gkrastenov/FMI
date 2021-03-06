#include <iostream>
using namespace std;

void removeBracket(char* arr,int index, int len)
{
	for (int i = index; i <= len; i++)
	{
		if (arr[i + 1] == '\0')
		{
			arr[i] = arr[i + 1];
			break;
		}
		arr[i] = arr[i + 1];
	}
}

void transfer(char* arr, int len)
{
	bool flag = false;
	for (int i = 0; i < len; i++)
	{
		if (arr[i] == '\0')
		{
			break;
		}

		if (arr[i] == '[')
		{
			removeBracket(arr, i,len);
			int index = i;
			while (arr[index] != ']')
			{
				if (arr[index] >= 'a'  && arr[index] <= 'z')
				{
					// arr[index] -= 32;
					arr[index] += 'A' - 'a'; 
				}
				index++;
			}
			i = index;
			removeBracket(arr, i, len);
		}
	}
}

int getLength(char* arr)
{
	int index = 0;
	int result = 0;
	while (arr[index] != '\0')
	{
		index++;
		result++;
	}
	return result - 1;
}
int main()
{
	// Input: Make this [word] [upper case. This [one] too.

	const int MAX_SIZE = 1000;
	char arr[MAX_SIZE];

	cin.getline(arr, MAX_SIZE - 1);

	int arrLen = getLength(arr);

	transfer(arr, arrLen);
	cout << arr;
}