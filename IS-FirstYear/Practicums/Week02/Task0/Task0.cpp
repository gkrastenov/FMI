// Task0.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
using namespace std;

int main()
{
    double a, b;
    cin >> a >> b;
    cout << "Vuvedete operator"<<endl;
    char oper;
    cin >> oper;
    switch (oper)
    {
    case '+': cout << a + b;
    break;

    case '-': cout << a - b;
    break;

    case '*': cout << a * b;
    break;

    case '/': cout << a / b;
    break;
    default:
    break;
    }
}
