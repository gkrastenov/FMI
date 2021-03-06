#include <iostream>

template<class T>
void input(T array[], int n) {
	std::cout << "Input: " << std::endl;

	for (size_t i = 0; i < n; i++)
	{
		std::cout << "array[" << i << "]: ";
		std::cin >> array[i];
	}
}

template<class T>
void print(T array[], int n) {
	std::cout << "Output " << std::endl;

	for (size_t i = 0; i < n; i++)
	{
		std::cout << "array[" << i << "]: " << array[i] << std::endl;
	}
}

int main()
{
	const int n = 5;
	int arrayInt[n];
	double arrayDouble[n];
	char arrayChar[n];

	input<int>(arrayInt, n);
	print<int>(arrayInt, n);

	// input<double>(arrayDouble, n);
	// print<double>(arrayDouble, n);

	// input<char>(arrayChar, n);
	// print<char>(arrayChar, n);
}

