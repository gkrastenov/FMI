// Task5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    const int size = 128;
    int arr[size];

    for (int i = 0; i < n; i++)
    {
        int number;
        cin >> number;
        arr[i] = number;
    }
    cout << "Print......" << endl;
    for (int i = n - 1; i >= 0; i--)
    {
        cout << arr[i] << endl;
    }

}
