// Task2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void reverseSemitrical(int *arr, int len)
{
    for (size_t i = 0; i < length; i++)
    {

    }
    int* firstNumber = arr;
    int* lastNumber = arr + len - 1;
    while (firstNumber < lastNumber)
    {
        swap(firstNumber, lastNumber);
        firstNumber++;
        lastNumber--;
    }
}
int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    reverseSemitrical(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
}