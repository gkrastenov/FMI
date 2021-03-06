// Task6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int USB = 0, RAM = 0, SSD = 0, laptopPrice = 0;
    cin >> USB >> RAM >> SSD >> laptopPrice;
    if (USB > 0 && RAM > 0 && SSD > 0)
    {
        if (laptopPrice >= 1000 && laptopPrice < 1500)
        {
            return true;
        }
        return false;
    }
    else {
        if (laptopPrice >= 800)
        {
            return false;
        }
        else {
            return true;
        }
    }
}
