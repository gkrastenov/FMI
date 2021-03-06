// Task4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    int n, result, number;
    result = 0;
    cin >> n >> number;
    if (n < 2 || n > 9)
    {
        cout << "Nevaliden vxod za n";
    }
    else {
        int stepen = 0;
        do
        {
            int current = number % 10;
            
            if (stepen == 0)
            {
                result += current;

            }
            else {
                int sum = current;
                for (int i = 1; i <= stepen; i++)
                {
                    sum *= n;
                }
                result += sum;
            }
            

            number = number / 10;
            stepen++;
        } while (number!= 0);
    }

    cout << result << endl;
    
}
