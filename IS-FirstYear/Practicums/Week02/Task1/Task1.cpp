// Task1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int year;
    cin >> year;
    if (year % 100 == 0)
    {
        if (year % 400 == 0)
        {
            cout << "Visokosna";
        }
        else {
            cout << "Ne e visokosna";
        }
    }
    else {
        if (year % 4 == 0)
        {
            cout << "Visokosna";
        }
        else {
            cout << "Ne e visokosna";
        }
    }
}