#pragma once
class Array
{
private:
	int* elements;
	int capacity;
	int size;

	void resize();
public:
	Array();
	~Array();
	void add(int element);
	bool contains(int element);
	bool empty();
	int count();
	bool full();
	void print();
};

