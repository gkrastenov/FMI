// Task2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>   
#include<cmath>
using namespace std;

string sumBinary(string a, string b)
{
    string result = ""; 
    int s = 0;          

    int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || s == 1)
    {
        s += ((i >= 0) ? a[i] - '0' : 0);
        s += ((j >= 0) ? b[j] - '0' : 0);

        result = char(s % 2 + '0') + result;

        s /= 2;
 
        i--; j--;
    }
    return result;
}
string  decToBinary(int n)
{
    string result = "";
    int number = 1;

    int binaryNum[32];

    // counter for binary array 
    int i = 0;
    while (n > 0) {

        // storing remainder in binary array 
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // printing binary array in reverse order 
    for (int j = i - 1; j >= 0; j--)
    {
        cout << binaryNum[j];
        result += to_string(binaryNum[j]);
    }
    cout << endl;
    return result;
}
int main()
{
	int length;
	cin >> length;

	int arr[128];
	int binArray[128];
    int decSum = 0;
    for (int i = 0; i < length; i++)
    {
        cin >> arr[i];
        decSum += arr[i];
    }

    double decAverage = decSum / length;

    string binarySum = "0";
    for (int i = 0; i < length; i++)
    {
        string number = decToBinary(arr[i]);
        binarySum = sumBinary(binarySum, number);
    }

    if (decSum % 10 == 0)
    {
        cout << decSum << endl;
        cout << binarySum << endl;
        cout << decAverage << endl;
        decToBinary(decSum); 
    }
    else {
        cout << decSum << endl;
        cout << binarySum << endl;
        cout << floor(decAverage) << endl;
        decToBinary(floor(decAverage));
    }
}
