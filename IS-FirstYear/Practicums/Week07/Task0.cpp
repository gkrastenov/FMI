#include <iostream>
using namespace std;

void swap(int* first, int* second)
{
	int* temp = first;
	first = second;
	second = temp;
}

int main()
{
	int a, b;
	cin >> a;
	cin >> b;
	
	swap(a, b);
}