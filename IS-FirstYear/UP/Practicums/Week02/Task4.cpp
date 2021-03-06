// Task4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    if (a == b && b == 0)
    {
        cout << "INF" << endl;
    }
    if (b % a == 0)
    {
        cout << (b * (-1)) / a << endl;
    }
    else {
        cout << "NO" << endl;
    }
}