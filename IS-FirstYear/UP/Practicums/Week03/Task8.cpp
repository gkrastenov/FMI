// Task8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    for (char i = 'A'; i <= 'Z'; i++) {
        if (i == 'A' || i == 'E' || i == 'I' || i == 'O' || i == 'U')
        {
            continue;
        }
        cout << i;
    }
    cout << endl;
}
