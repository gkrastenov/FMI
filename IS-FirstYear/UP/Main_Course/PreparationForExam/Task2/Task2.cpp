// Task2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// TODO: 
#include <iostream>
using namespace std;

const int SIZE = 128;
int main()
{
    char firstInput[128];
    char secondInput[128];
    cin.getline(firstInput, SIZE);
    cin.getline(secondInput, SIZE);

    bool flag = true;
    int firstCounter = 0;
    int secondCounter = 0;

    int index = 0;
    while (flag)
    {
        char currentValue = firstInput[index];
        for (int i = 0; i < SIZE; i++)
        {
            if (firstInput[i] == '\0')
            {
                break;
            }

            if (currentValue == firstInput[i])
            {
                firstCounter++;
            }
        }

        for (int i = 0; i < SIZE; i++)
        {
            if (firstInput[i] == '\0')
            {
                break;
            }

            if (currentValue == firstInput[i])
            {
                secondCounter++;
            }
        }

        if (firstCounter != secondCounter)
            flag = false;

        if (firstInput[index + 1] == '\0')
        {
            break;
        }
        index++;
    }

    std::cout << "Hello World!\n";
}