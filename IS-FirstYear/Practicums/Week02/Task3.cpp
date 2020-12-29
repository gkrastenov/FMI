// Task3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int number;
    cin >> number;
    int month = number / 4;
    switch (month)
    {
    case 0: cout << "Spring" << endl;
        break;
    case 1: cout << "Summer" << endl;
        break;
    case 2: cout << "Autumn" << endl;
        break;
    case 3: cout << "Winter" << endl;
        break;
    default:
        break;
    }
}