// Task0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    int n;
    long factorial = 1;

    cout << "Enter a positive integer: ";
    cin >> n;

    if (n==0)
    {
        cout << "Factorial of " << n << " = " << 1;
    }
    else {
        for (int i = 1; i <= n; ++i)
        {
            factorial *= i;
        }

        cout << "Factorial of " << n << " = " << factorial;
    }

}
