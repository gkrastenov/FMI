#include <iostream>
using namespace std;

int countNumber(string text, int index)
{
	if (index == text.length())
	{
		return 0;
	}

	// 48 and 57 are values form ASCII table
	if (text[index] >= 48 && text[index] <= 57)
	{
		return countNumber(text, index + 1) + 1;
	}
	return countNumber(text, index+1);
}

int main()
{
    string input;
    cin >> input;
    cout << countNumber(input, 0) << endl;
}
