// Task3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "N =";
    cin >> n;
    long sum = 0;
    if (n == 0 || n == 1 || n == 2)
    {
        cout << n << " from fibonacci is " <<1<< endl;
    }
    else {
        int prev = 1;
        int next = 1;

        for (int i = 2; i < n; i++)
        {
            sum = prev + next;
            prev = next;
            next = sum;
        }
        cout << n << " from fibonacci is " << sum << endl;
    }
}
