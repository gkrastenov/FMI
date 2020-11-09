// Task2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "N = ";

    cin >> n;

    int minimum = 0;
    for (int i = 0; i < n; i++)
    {
        int number;
        cin >> number;
        if (number< minimum)
        {
            minimum = number;
        }
    }

    if (minimum!=0)
    {
        cout << "The smallest number is " << minimum << endl;
    }
    else {
        cout << "You didn't write negative numbers" << endl;
    }
}
