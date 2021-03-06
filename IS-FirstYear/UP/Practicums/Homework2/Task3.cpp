#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

int main()
{
	string input;
	cin >> input;
	int number;
	cin >> number;

	string result = "";
	int currentValue = 0;
	for (int i = 0; i < input.length(); i++)
	{
		if (isupper(input[i]))
		{
			if (input[i] - number < 'A')
			{
				currentValue = number - (input[i] - 'A');
				result += 'W' - currentValue;
			}
			else {
				result += input[i] - number;
			}
		}
		else {
			if (input[i] - number < 'a')
			{
				currentValue = number - (input[i] - 'a');
				result += 'w' - currentValue;
			}
			else {
				result += input[i] - number;
			}
		}
		currentValue = 0;
	}

	cout << result;
}