#pragma once
#include "Product.h"

class File
{
private:
	size_t MAX_CONSOLE_COMMAND = 20;

	char* fileName;
	bool isOpen;
	bool isCreated;

	Product* products;
	int count;
	int capacity;

	char* enterString(const size_t length);
	void write();
	void read();
	void menuView();
	bool compareStrings(const char* input, const char* source,
		const size_t inputSize, const size_t commandSize);
	size_t getSize(const char* source);
	bool isExists(const char* fileName);
public:
	File();
	~File();

	void initialCreate();
	bool add();
	bool print();
	bool exit();
	bool help();
	bool saveAs();
	
	bool menu();
	void setFileName(const char* name);
	char* getFileName();
};

