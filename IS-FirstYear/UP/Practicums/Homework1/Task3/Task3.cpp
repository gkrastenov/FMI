// Task3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>

using namespace std;

const char bigBear[14] = { '0', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
'i', 'j', 'k', 'l', 'm' };
const char earth[14] = { '0', '1', '2', '3', '4', '5', '6', '7', '8',
'9', 'a', 'b', 'c', 'd' };
bool isWorking = false;

int searchInBigBear(char param)
{
    for (int i = 0; i < sizeof(bigBear); i++)
    {
        if (bigBear[i] == param)
        {
            return i;
        }
    }
}
int searchInEarth(char param)
{
    for (int i = 0; i < sizeof(earth); i++)
    {
        if (earth[i] == param)
        {
            return i;
        }
    }
}
void zellersAlgorithm(int day, int month, int year) {
    int mon;
    if (month > 2)
        mon = month;    //for march to december month code is same as month
    else {
        mon = (12 + month);    //for Jan and Feb, month code will be 13 and 14
        year--; //decrease year for month Jan and Feb
    }

    int y = year % 100;    //last two digit
    int c = year / 100;    //first two digit
    int w = (day + floor((13 * (mon + 1)) / 5) + y + floor(y / 4) + floor(c / 4) + (5 * c));
    w = w % 7;
    
    if (w == 5 || w == 6)
    {
        isWorking = true;
    }
    else {
        isWorking = false;
    }
}
void printNumber(int number)
{
    if (number < 14)
    {
        cout << number << " -> " << bigBear[number];
    }
    else {
        char helper[120];
        int index = 0;
        int n = number;
            do
            {
                helper[index] = n % 10;
                n = n / 10;
                index++;
            } while (n != 0);
            cout << number << " -> ";
            for (int i = index; i >= 0; i--)
            {
                cout<< bigBear[helper[i]];
            }
    }
}
int main()
{
    char input[128];
    int n;
    cin >> n;

    int translatedInput[128];
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    int secondInput;
    cin >> secondInput;

    int arrayForYear[128];
    int dots = 0;
    int index = 0;
    for (int i = 0; i < n; i++)
    {

        if (input[i] == '.')
        {
            dots++;
            continue;
        }

        translatedInput[index] = searchInBigBear(input[i]);
        index++;
    }
    int day = translatedInput[0];
    int month = translatedInput[1];

    index = 0;
    char convertedArray[126];
    for (int i = 2; i < n-dots; i++) // remove number of dots;
    {
        convertedArray[index] = earth[(translatedInput[i])];
        index++;
    }

    index = 0;
    int year = 0;
    for (int i = 0; i < n-dots-2; i++)
    {
        year += searchInEarth(convertedArray[i]) * (pow(14, i));
    }

    zellersAlgorithm(day, month, year);
    if (isWorking)
    {
        cout << "No, " << day << "." << month << "." << year << " is a working day. ";
        printNumber(secondInput);
    }
    else {
        cout << "Yes, " << day << "." << month << "." << year << " is not a working day. ";
        printNumber(secondInput);
    }

}
