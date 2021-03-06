// Task2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    cout << "Enter symbol" << endl;
    char symbol;
    cin >> symbol;
    int parameter = (unsigned int)symbol;
    char output = parameter;
    if (parameter >= 97 && parameter <= 122)
    {

        output = (parameter - 32);
        cout << "The lower case character corresponding to is " << output << endl;
        return;
    }
    if (parameter >= 65 && parameter <= 90)
    {
        output = (unsigned char)(parameter + 32);
        cout << "The upper case character corresponding to is " << output << endl;
        return;
    }

    cout << "Is not letter";
}