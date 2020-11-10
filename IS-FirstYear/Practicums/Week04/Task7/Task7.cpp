// Task7.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
        cin >> arr[i];
    }
    int firstIndex = 0;
    int lastIndex = n-1;
    bool flag = true;
    while (firstIndex < lastIndex)
    {
        if (arr[firstIndex] == arr[lastIndex])
        {
            firstIndex++;
            lastIndex--;
        }
        else {
            flag = false;
            break;
        }
    }
    cout << boolalpha << flag << endl;
}
