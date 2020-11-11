// Task2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

// function to convert decimal to binary 
bool decToBinary(int n) 
{ 
    // array to store binary number 
    int binaryNum[32]; 
  
    // counter for binary array 
    int index = 0;
    while (n > 0) { 
  
        binaryNum[index] = n % 2;
        n = n / 2; 
        index++; 
    } 
  
    int zeroCount = 0;
    int oneCount = 0;

    for (int i = 0; i < index; i++)
    {
        if (binaryNum[i] == 0)
        {
            zeroCount++;
        }

        if (binaryNum[i] == 1)
        {
            oneCount++;
        }
    }


    if (zeroCount == oneCount)
    {
        // printing binary array in reverse order 
        for (int j = index - 1; j >= 0; j--)
        {
            cout << binaryNum[j];
        }
        cout << endl;
        return true;
    }
    return false;
} 

int main()
{
    int n;
    cout << "N = " << endl;
    cin >> n;

    int number = 1;
    bool IsCorrect = false;
    do
    {
        IsCorrect = decToBinary(number);
        if (IsCorrect)
        {
            n--;
        }

        number++;
    } while (n!=0);
}

