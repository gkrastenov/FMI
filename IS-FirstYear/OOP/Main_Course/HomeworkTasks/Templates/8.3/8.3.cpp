#include <iostream>

template<class T>
bool member(T array[], int n, T x)
{
	for (size_t i = 0; i < n; i++)
	{
		if (array[i] == x)
			return true;
	}

	return false;
}

template<class T>
void input(T array[], int n) {
	std::cout << "Input: " << std::endl;

	for (size_t i = 0; i < n; i++)
	{
		std::cout << "array[" << i << "]: ";
		std::cin >> array[i];
	}
}
int main()
{
	const int n = 5;
	int arrayInt[n];
	bool a = true;
	input<int>(arrayInt, n);
	std::cout << std::boolalpha << member(arrayInt, n,2);
}
