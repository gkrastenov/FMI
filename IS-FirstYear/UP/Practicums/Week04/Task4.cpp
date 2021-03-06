// Task4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    int n, negative, index;
    const int  size = 100;
    cin >> n;
    bool flag = true;
    int arr[size];

    for (int i = 0; i < n; i++)
    {
        int number;
        cin >> number;
        arr[i] = number;
        if (number <0 && flag == true)
        {
            negative = number;
            index = i;
            flag = false;
        }
    }

    if (flag == true)
    {

    }
    else {
        int sum = 0;
        for (int i = index + 1; i < n; i++)
        {
            sum += arr[i];
        }

        cout << "The negative number is: " << negative << endl;
        cout << "Sum is: " << sum << endl;
    }
  



}
