// Task7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{

    int number;
    cin >> number;
    int firstNumber = number / 1000;
    bool odd = false;
    if (firstNumber % 2 == 0)
    {
        odd = true;
    }

    int secondNumber = number / 100 % 10;
    int thirdNumber = number / 10 % 10;
    int lastNumber = number % 10;

    if (odd && firstNumber > secondNumber
        && firstNumber > thirdNumber && firstNumber > lastNumber)
    {
        cout << "True" << endl;
    }
    else {
        cout << "False" << endl;

    }
}
