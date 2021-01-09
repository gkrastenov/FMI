#include <iostream>
using namespace std;

bool isContainsSymbol(char symbol, string text, int startTextIndex)
{
    if (startTextIndex >= text.length())
    {
        return false;
    }

    if (symbol == text[startTextIndex])
    {
        return true;
    }
    else {
        return (symbol, text, startTextIndex + 1);
    }
}

bool isContains(string input, int startInputIndex, string text)
{
    if (startInputIndex >= input.length())
    {
        return true;
    }

    if (isContainsSymbol(input[startInputIndex], text, 0))
    {
        return isContains(input, startInputIndex + 1, text);
    }
    else {
        return false;
    }
}

int main()
{
    string input, text;
    cin >> input >> text;
    bool flag = isContains(input, 0, text);
    if (flag)
    {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
}