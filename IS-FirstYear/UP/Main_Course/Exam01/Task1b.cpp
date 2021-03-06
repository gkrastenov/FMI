// Task1b.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

/// <summary>
/// Exercise 1. B)
/// </summary>
int main()
{
    int number;
    cin >> number;

    if (number > 999 || number < 100)
    {
        cout << "Incorrect input" << endl;
    }
    else {

        int firstNumber = number / 100;
        int secondNumber = number / 10 % 10;
        int thirdNumber = number % 10;
        if (firstNumber == secondNumber || secondNumber == thirdNumber || firstNumber == thirdNumber)
        {
            if (firstNumber == secondNumber)
            {
                cout << boolalpha << true;
            }
            if (firstNumber == thirdNumber)
            {
                cout << boolalpha << true;
            }
            if (secondNumber == thirdNumber)
            {
                cout << boolalpha << true;
            }
        }
        else {
            cout << boolalpha << false;
        }
    }
}