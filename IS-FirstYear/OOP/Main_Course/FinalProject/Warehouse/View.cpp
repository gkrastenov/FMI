#include "View.h"
#include <iostream>
using namespace std;

View::View()
{
	file = File();
}
bool View::menu()
{
	menuView();

	char consoleCommand[20];
	cin.getline(consoleCommand, 20);

	if (compareStrings(consoleCommand, "open", getSize(consoleCommand), 4))
	{
		return file.open();
	}
	if (compareStrings(consoleCommand, "close", getSize(consoleCommand), 5))
	{
		return file.close();
	}
	if (compareStrings(consoleCommand, "save", getSize(consoleCommand), 4))
	{
		return file.save();
	}
	if (compareStrings(consoleCommand, "saveas", getSize(consoleCommand), 6))
	{
		return file.saveAs();
	}
	if (compareStrings(consoleCommand, "help", getSize(consoleCommand), 4))
	{
		return file.saveAs();
	}
	if (compareStrings(consoleCommand, "exit", getSize(consoleCommand), 4))
	{
		return file.exit();
	}

	return false;
}

void View::menuView()
{
	cout << "-------- Menu --------" << endl;
	cout << "Open (open)" << endl;
	cout << "Close (close)" << endl;
	cout << "Save (save)" << endl;
	cout << "Save As (saveas)" << endl;
	cout << "Help (help)" << endl;
	cout << "Exit (exit)" << endl;
}

bool View::compareStrings(const char* input, const char* source, 
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

size_t View::getSize(const char* source)
{
	int index = 0;
	while (source[index] != '\0')
	{
		index++;
	}

	return index;
}