// Task5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{

    int month, year;
    cin >> month >> year;
    switch (month)
    {
    case 1:cout << "31" << endl;
        break;
    case 2: if (year % 4 == 0)
    {
        cout << "29" << endl;
    }
          else {
        cout << "28" << endl;

    }
          break;
    case 3:cout << "31" << endl;
        break;
    case 4: cout << "30" << endl;
        break;
    case 5:  cout << "31" << endl;
        break;
    case 6: cout << "30" << endl;
        break;
    case 7:  cout << "31" << endl;
        break;
    case 8:  cout << "31" << endl;
        break;
    case 9:  cout << "30" << endl;
        break;
    case 10: cout << "31" << endl;
        break;
    case 11: cout << "30" << endl;
        break;
    case 12: cout << "31" << endl;
        break;
    default:
        break;
    }
}
