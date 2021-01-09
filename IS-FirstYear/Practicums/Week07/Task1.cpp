#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

void swap(int *first, int *second)
{
    *first = *first * *second;
    *second = *first / *second;
    *first = *first / *second;

}

void reverse(int arr[], int length)
{
    int *firstNumber = arr;
    int *lastNumber = arr + length- 1;
    while (firstNumber<lastNumber)
    {
        swap(firstNumber, lastNumber);
        firstNumber++;
        lastNumber--;
    }
}
int main()
{
    int arr[] = { 1, 2 ,3 , 4, 5, 6, 7, 8, 9, 10 };
    int length = sizeof(arr) / sizeof(arr[0]);
    reverse(arr, length);
    
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] <<" ";
    }
}
