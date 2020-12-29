#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int firstDegit = n / 100;
    cout << "First Degit: ";
    cout << firstDegit << endl;
    int secondDegit = n / 10 % 10;

    cout << "Second Degit: ";
    cout << secondDegit << endl;

    int thirdDigit = n % 10;
    cout << "Third Degit: ";
    cout << thirdDigit << endl;

    cout << "Sum of all degits is :" << firstDegit + secondDegit + thirdDigit << endl;
}
