#include <iostream>
#include <fstream>
#include "File.h"

using namespace std;

int main()
{
	const char* fileName = "warehouse";
	File myFile = File(fileName);
	
	cout << "Welcome, this is your program who will help you to manage sucseesfuly your warehouse" << endl;
}