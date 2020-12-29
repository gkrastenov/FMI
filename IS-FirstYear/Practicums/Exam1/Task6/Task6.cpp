// Task6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    int n;
    const int size = 128;
    char arr[size];
    cin >> n;

    int sumEven = 0;
    int sumOdd = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (i==0)
        {
            sumEven += (int)arr[i];
            continue;
        }

        if (i % 2 == 0)
        {
            sumEven += (int)arr[i];

        }
        else {
            sumOdd += (int)arr[i];
        }
    }

    if (sumEven>sumOdd)
    {
        if (sumEven % sumOdd == 0)
        {
            cout << "The biggest sum is:" << sumEven << " and " << sumOdd << " is diveder " << endl;
        }
        else {
            cout << "The biggest sum is:" << sumEven << " and " << sumOdd << " is not diveder " << endl;
        }
    }
    else {
        if (sumOdd % sumEven == 0)
        {
            cout << "The biggest sum is:" << sumOdd << " and " << sumEven << " is diveder " << endl;
        }
        else {
            cout << "The biggest sum is:" << sumOdd << " and " << sumEven << " is not diveder " << endl;
        }
    }
   
}
