#include <iostream>

template<class T>
bool ordered(T array[], int n)
{
	if (n == 1)
		return true;

	for (size_t i = 0; i < n - 1; i++)
	{
		if ((array[i] < array[i + 1] )== false)
			return false;
	}

	return true;
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
	std::cout << std::boolalpha << ordered(arrayInt, n);
}
