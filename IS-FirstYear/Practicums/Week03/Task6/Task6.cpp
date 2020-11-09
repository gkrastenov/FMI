// Task6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<cmath>
using namespace std;
int main()
{
    int n, step, result = 1;
    cin >> n >> step;
    
   // pow(n, step);
    for (int i = 0; i < step; i++)
    {
        result = result * n;
    }

    cout << "The result is: " << result << endl;
}

