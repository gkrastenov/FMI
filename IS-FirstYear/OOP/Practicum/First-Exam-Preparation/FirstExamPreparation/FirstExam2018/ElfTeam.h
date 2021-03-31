#pragma once
#include "Elf.h"
#include<iostream>
class ElfTeam
{
private:
	const int MAX_NAME = 30;
	const int MAX_NUMBERS = 50;
	const int MIN_NUMBERS = 0;

	char* name;
	Elf* elfs;
	int numbers;
public:
	ElfTeam();
	ElfTeam(const ElfTeam& team);
	ElfTeam(const char* name, const Elf* elfs, const int number);
	~ElfTeam();

	void setName(const char* name);
	void setElfs(const Elf* elfs, const int numbers);
	void setNumbers(const int numbers);

	char* getName() const;
	Elf* getElfs() const;
	int getNumbers() const;

	ElfTeam& operator=(const ElfTeam& team);
	bool operator<(const ElfTeam& other);
	ElfTeam& operator+(const ElfTeam& other);
	void operator+=(const ElfTeam& other);

	friend std::ostream& operator<<(std::ostream& os, ElfTeam& team);

	bool contains(const Elf& elf);
	void addElf(const Elf& elf);
};

