#pragma once
class File
{
private:
	char* fileName;
	bool isOpen;
	bool isCreated;

public:
	File();
	File(const char* name);
	~File();

	void create();
	bool open();
	bool close();
	bool save();
	bool saveAs();
	bool help();
	bool exit();
};

