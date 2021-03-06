// Task3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    int n, max, min, minIndex = 0, maxIndex = 0;
    const int  size = 100;
    cin >> n;
    int arr[size];

    for (int i = 0; i < n; i++)
    {
        int number;
        cin >> number;
        arr[i] = number;

        if (i == 0)
        {
            max = number;
            min = number;
            continue;
        }

        if (max < number)
        {
            max = number;
            maxIndex = i;
        }

        if (number < min)
        {
            min = number;
            minIndex = i;
        }
    }

    int temp = arr[maxIndex];
    arr[maxIndex] = arr[minIndex];
    arr[minIndex] = temp;

    cout << "New array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i]<< endl;
    }
    cout << "Max: " << max << endl;
    cout << "Min: " << min << endl;
}
