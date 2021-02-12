// Task3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

const int MAX_SIZE = 128;
void function(char* array, int len)
{

    int index = 0;
    while (array[index] != '\0')
    {
        cout << array[index];
        for (int i = 0; i <= len; i++)
        {
            if (i == index)
            {
                continue;
            }
            cout << array[i];
        }
        cout << endl;


        for (int i = len; i >= 0; i--)
        {
            if (i == index)
            {
                cout << array[index];
                continue;
            }
            cout << array[i];
        }
        cout << endl;
        index++;
    }
}
int main()
{

    char array[MAX_SIZE];
    cin.getline(array, MAX_SIZE);
    
    int len = 0;
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (array[i] == '\0')
        {
            len = i - 1;
        }
    }
    function(array, len);
}
