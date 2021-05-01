#pragma once
class File
{
private:
	char* name;
	bool isOpen;
public:
	File();
	File(const char* name);
	~File();

	void create();
	void open();
	void close();
	void save();
	void saveAs();
	void help();
	void exit();
};

