#include <iostream>
#include <fstream>
#include <cstdlib>
#include <filesystem>
#include <string>
#include <chrono>
#include <ctime>  
#pragma warning(disable : 4996)
#include "File.h"

using namespace std;

File::File()
{
	fileName = nullptr;
	isOpen = false;
	isCreated = false;;
    products = nullptr;
	count = 0;
	capacity = 4;
	products = new Product[capacity];

	initialCreate();
}

File::~File()
{
	delete[] fileName;
	delete[] products;

	fileName = nullptr;
	isOpen = false;
	isCreated = false;;
	products = nullptr;
	count = 0;
	capacity = 0;
}

bool File::add()
{
	Product product = Product();
	cout << "Enter product description" << endl;
	product.setDescription(enterString(product.MAX_DESCRIPTION_LENGTH));

	cout << "Enter expiry date time (example: 2021/12/23)" << endl;
	product.setExpiryDate(enterString(10));

	cout << "Enter entry date time (example: 2020/12/23)" << endl;
	product.setEntryDate(enterString(10));

	cout << "Enter product manufacturer" << endl;
	product.setManufacturer(enterString(product.MAX_MANUFACTURER_LENGTH));

	cout << "Enter product unit (0 for Kilograms , 1 for Liters)" << endl;
	int unit;
	cin >> unit;
	product.setUnit(unit);

	cout << "Enter quantity:" << endl;
	int quantity;
	cin >> quantity;
	product.setQuantity(quantity);

	cout << "Enter location:" << endl;
	int location;
	cin >> location;
	product.setLocation(location);

	cout << "Enter product comment" << endl;
	cin.ignore();
	product.setComment(enterString(product.MAX_COMMENT_LENGTH));

	if (count + 1 > capacity)
	{
		capacity *= 2;
		Product* newProduct = new Product[capacity];
		delete[] products;
		products = newProduct;

		products[count] = product;
		count++;
	}
	else {
		products[count] = product;
		count++;
	}

	write(fileName);
	return true;
}

char* File::enterString(const size_t length)
{
	char* str = new char[length + 1];
	std::cin.getline(str, length + 1);
	return str;
}

void File::initialCreate()
{
	ofstream MyFile("warehouse.txt");
	setFileName("warehouse.txt");
}

char* File::getFileName() {
	return this->fileName;
}

void File::setFileName(const char* name) {
	size_t lengthName = strlen(name) + 1;
	this->fileName = new char[lengthName];
	strcpy_s(this->fileName, lengthName, name);
}

void File::write(const char* fileName) {
	ofstream myfile;
	myfile.open(fileName);
	for (size_t i = 0; i < count; i++)
	{
		myfile << products[i].getDescription() << endl;

		DateTime currDate = products[i].getExpiryDate();
		myfile << currDate.getYear() << '/' << currDate.getMonth() << '/'
			<< currDate.getDay() << endl;

		currDate = products[i].getEntryDate();
		myfile << currDate.getYear() << '/' << currDate.getMonth() << '/'
			<< currDate.getDay() << endl;

		myfile << products[i].getManufacturer() << endl;
		myfile << products[i].unitToNumber(products[i].getUnit()) << endl;
		myfile << products[i].getQuantity() << endl;
		myfile << products[i].getLocation() << endl;
		myfile << products[i].getComment() << endl;
	}
	
	myfile.close();
}

void File::read()
{
	string line;
	ifstream myfile("warehouse.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			cout << line << '\n';
		}
		myfile.close();
	}
}

bool File::print()
{
	for (size_t i = 0; i < count; i++)
	{
		cout << endl;
		cout << "product " << i << endl;
		products[i].printProduct();
	}

	return true;
}

bool File::menu()
{
	menuView();

	char consoleCommand[20];
	cin.getline(consoleCommand, 20);

	if (compareStrings(consoleCommand, "add", getSize(consoleCommand), 3))
	{
		if (add())
		{
			cout << "has been added new product" << endl;;
			return true;
		}
		else {
			cout << "Has not been added new product" << endl;;
			return false;
		}
	}
	if (compareStrings(consoleCommand, "exit", getSize(consoleCommand), 4))
	{
		return exit();
	}
	if (compareStrings(consoleCommand, "help", getSize(consoleCommand), 4))
	{
		return help();
	}
	if (compareStrings(consoleCommand, "save as", getSize(consoleCommand), 7))
	{
		return saveAs();
	}
	if (compareStrings(consoleCommand, "print", getSize(consoleCommand), 5))
	{
		return print();
	}
	if (compareStrings(consoleCommand, "clean", getSize(consoleCommand), 5))
	{
		return clean();
	}

	cout << "Invalid command" << endl;
	return true;
}

void File::menuView()
{
	cout << "-------- Menu --------" << endl;
	cout << "Add (add)" << endl;
	cout << "Print (print)" << endl;
	cout << "Exit (clean)" << endl;
	cout << "Save As (save as)" << endl;
	cout << "Help (help)" << endl;
	cout << "Exit (exit)" << endl;
}

bool File::compareStrings(const char* input, const char* source,
	const size_t inputSize, const size_t commandSize)
{
	if (inputSize != commandSize)
	{
		return false;
	}

	for (size_t i = 0; i < commandSize; i++)
	{
		if (input[i] != source[i])
		{
			return false;
		}
	}

	return true;
}

size_t File::getSize(const char* source)
{
	int index = 0;
	while (source[index] != '\0')
	{
		index++;
	}

	return index;
}

bool File::exit()
{
	cout << "Exit successfully." << endl;
	return false;
}

bool File::help()
{
	cout << "add : Add a new product to the warehouse" << endl;
	cout << "print : Displays information about the products available in the warehouse" << endl;
	cout << "save as : Save warehouse in other file" << endl;
	cout << "exit : Exit from the program" << endl;

	return true;
}

bool File::isExists(const char* fileName)
{
	fstream fileStream;
	fileStream.open(fileName);
	if (fileStream.fail()) {
		return false;
	}
	return true;
}

bool File::saveAs()
{
	cout << "Enter new file name: (Example: other.txt)" << endl;
	// TODO: check for correct file name
	char name[20];
	cin.getline(name, 20);

	ofstream MyFile(name);
	write(name);
	return true;
}

bool File::clean()
{
	std::time_t time = std::time(0);   // get time now
	std::tm* now = std::localtime(&time);
	DateTime dateNow = DateTime((now->tm_year + 1900), (now->tm_mon + 1), now->tm_mday);

	cout << "Cleanning: " << endl;
	int index = 0;
	while (index<count)
	{
		if (products[index].getExpiryDate() <= dateNow)
		{
			cout << "Product: " << endl;
			products[index].printProduct();
			removeProduct(index);
		}
		index++;
	}

	return true;
}

void File::removeProduct(const size_t index)
{
	count--;
	for (size_t i = index; i < count; i++)
	{
		products[i] = products[i + 1];
	}
}