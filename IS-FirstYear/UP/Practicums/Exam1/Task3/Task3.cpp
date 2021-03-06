// Task3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;

    const int size = 128;
    int arr[size];

    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i]<10)
        {
            counter++;
        }
        else
        {
            int number = arr[i];
            int sum = 1;
            do
            {
                sum *= number % 10;
                number = number / 10;
            } while (number != 0);

            if (sum < 10)
            {
                counter++;
            }
        }
    }

    if (counter != 0)
    {
        cout << "The result is: " << counter << endl;
    }
    else {

        cout << "Not Found "<< endl;
    }
   
}
