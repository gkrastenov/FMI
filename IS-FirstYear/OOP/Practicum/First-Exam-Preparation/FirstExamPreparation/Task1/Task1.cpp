#include <iostream>
#include "Array.h"

using namespace std;
int main()
{
    Array array = Array();
    array.add(10);
    array.add(20);
    array.add(30);
    array.add(40);
    array.add(50);
    array.add(60);
    array.add(70);
    array.add(80);
    cout << "Array contains 100: " << boolalpha << array.contains(100) << endl;
    cout << "Array contains 10: " << boolalpha << array.contains(10) << endl;
    cout << "Count:" << array.count() << endl;
    cout << "Array is full 10: "<< array.full() << endl;
    array.add(100);
    cout << "Added 100" << endl;
    cout << "Array contains 100: " << boolalpha << array.contains(100) << endl;
    cout << "Array contains 10: " << boolalpha << array.contains(10) << endl;
    cout << "Count:"<< array.count() << endl;

    cout << "Printing all elements in array...." << endl;
    array.print();
}
