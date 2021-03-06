#include <iostream>
using namespace std;

bool findTheThirdOne(double num, double* arr, double toWhat, int size, double n) {
    for (int i = size - 1; i > toWhat; --i) {
        if (num * arr[i] == n) {
            return true;
        }
    }
    return false;
}
bool recursiveMultiplication(double* arr, int size, int sizeEnd, int index, double n) {
    if (sizeEnd == 0) {
        return false;
    }
    double num = arr[0] * arr[1];
    if (findTheThirdOne(num, arr, index + 1, size, n)) {
        return true;
    }
    return recursiveMultiplication(arr + 1, size, sizeEnd - 1, index + 1, n);
}
int main()
{
    double arr[7] = { 5, 2, 1, 10, 4, 9, 1 }, n = 6;
    bool answ = recursiveMultiplication(arr, 7, 7, 0, n);
    if (answ) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}