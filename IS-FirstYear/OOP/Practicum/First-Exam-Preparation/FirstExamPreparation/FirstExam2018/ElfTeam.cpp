#include "ElfTeam.h"
#include<iostream>

ElfTeam::ElfTeam()
{
	this->name = nullptr;
	this->elfs = nullptr;
	this->numbers = MIN_NUMBERS;
}
ElfTeam::ElfTeam(const ElfTeam& team)
{
	setName(team.name);
	setElfs(team.elfs, team.numbers);
	setNumbers(team.numbers);
}
ElfTeam::ElfTeam(const char* name, const Elf* elfs, const int number)
{
	setName(name);
	setElfs(elfs, numbers);
	setNumbers(numbers);
}
ElfTeam::~ElfTeam()
{
	delete[] name;
	delete[] elfs;
	this->name = nullptr;
	this->elfs = nullptr;
	this->numbers = MIN_NUMBERS;
}
int ElfTeam::getNumbers() const
{
	return this->numbers;
}
char* ElfTeam::getName() const
{
	return this->name;
}
Elf* ElfTeam::getElfs() const
{
	return this->elfs;
}
void ElfTeam::setNumbers(const int numbers)
{
	if (numbers >= MIN_NUMBERS && numbers <= MAX_NUMBERS)
	{
		this->numbers = numbers;
	}
	else {
		this->numbers = MIN_NUMBERS;
	}
}
void ElfTeam::setName(const char* name)
{
	size_t length = strlen(name) + 1;
	if (length - 1 == 0)
	{
		this->name = new char[1];
		strcpy_s(this->name, length, "");
	}
	else {
		this->name = new char[length];
		strcpy_s(this->name, length, name);
	}
}
void ElfTeam::setElfs(const Elf* elfs, const int numbers)
{
	delete[] this->elfs;
	this->elfs = new Elf[numbers];
	for (size_t i = 0; i < numbers; i++)
	{
		this->elfs[i] = elfs[i];
	}
	this->numbers = numbers;
}
void ElfTeam::addElf(const Elf& elf)
{
	if (this->numbers >= MAX_NUMBERS)
	{
		std::cout << "Team is full" << std::endl;
	}
	else {
		this->elfs[numbers] = elf;
		this->numbers++;
	}
}
std::ostream& operator<<(std::ostream& os, ElfTeam& team)
{
	std::cout << "Name: " << std::endl;
	os << team.getName();
}
ElfTeam& ElfTeam::operator=(const ElfTeam& team)
{
	if (this != &team)
	{
		delete[] name;
		delete[] elfs;
		setName(team.name);
		setElfs(team.elfs, team.numbers);
		setNumbers(team.numbers);

	}
	return *this;
}
bool ElfTeam::operator<(const ElfTeam& other)
{
	int sumA = 0;
	int sumB = 0;
	for (size_t i = 0; i < this->numbers; i++)
	{
		sumA += this->elfs[i].getAge() + this->elfs[i].getAbility();
	}
	for (size_t i = 0; i < other.numbers; i++)
	{
		sumB += other.elfs[i].getAge() + other.elfs[i].getAbility();
	}
	
	if (sumA<sumB)
	{
		return true;
	}
	return false;
}
void ElfTeam::operator+=(const ElfTeam& other)
{
	if (this->getNumbers() != 50 || other.numbers > 0)
	{
		for (size_t i = 0; i < other.numbers; i++)
		{
			if (this->numbers == 50)
			{
				break;
			}

			if (this->contains(other.elfs[i]))
			{
				continue;
			}
			else {
				this->addElf(other.elfs[i]);
			}
		}
	}
}
ElfTeam& ElfTeam::operator+(const ElfTeam& other)
{
	ElfTeam newTeam = ElfTeam();
	// add first team
	if (this->numbers != 0)
	{
		for (size_t i = 0; i < this->numbers; i++)
		{
			if (i == 50)
			{
				break;
			}
			newTeam.addElf(this->elfs[i]);
		}
	}

	// add second team
	if (other.numbers > 0 || newTeam.getNumbers() != 50)
	{
		for (size_t i = 0; i < other.numbers; i++)
		{
			if (newTeam.numbers == 50)
			{
				break;
			}

			if (newTeam.contains(other.elfs[i]))
			{
				continue;
			}
			else {
				newTeam.addElf(other.elfs[i]);
			}
		}
	}
	
	return newTeam;
}
bool ElfTeam::contains(const Elf& elf)
{
	for (size_t i = 0; i < this->numbers; i++)
	{
		Elf currentElf = Elf(elfs[i]);
		if (currentElf.getAbility() == elf.getAbility() && currentElf.getAge() == elf.getAge() &&
			(strcmp(currentElf.getName(), elf.getName()) == 0 ) )
		{
			return true;
		}
	}
	return false;
}