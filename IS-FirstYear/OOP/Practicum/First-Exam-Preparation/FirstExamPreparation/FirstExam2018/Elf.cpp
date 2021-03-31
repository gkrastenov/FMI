#include "Elf.h"
#include<iostream>
Elf::Elf()
{
	this ->name = nullptr;
	this->age = MIN_AGE;
	this->ability = MIN_ABILITY;
}
Elf::Elf(const Elf& elf)
{
	setName(elf.name);
	setAge(elf.age);
	setAbility(elf.ability);

}
Elf::Elf(const char* name, const int age, const int ability)
{
	setName(name);
	setAge(age);
	setAbility(ability);
}
Elf::~Elf()
{
	delete[] name;
	this->name = nullptr;
	this->age = MIN_AGE;
	this->ability = MIN_ABILITY;
}
int Elf::getAbility() const
{
	return this->ability;
}
int Elf::getAge() const
{
	return this->age;
}
char* Elf::getName() const
{
	return this->name;
}

void Elf::setName(const char* name)
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
void Elf::setAge(const int age)
{
	if (age >= MIN_AGE && age <= MAX_AGE)
	{
		this->age = age;
	}
	else {
		this->age = MIN_AGE;
	}
}

void Elf::setAbility(const int ability)
{
	if (ability >= MIN_ABILITY && ability <= MAX_ABILITY)
	{
		this->ability = ability;
	}
	else {
		this->ability = MIN_ABILITY;
	}
}
std::ostream& operator<<(std::ostream& os, Elf& elf) {
	std::cout << "Name: " << std::endl;
	os << elf.getName();
	std::cout << "Age: " << std::endl;
	os << elf.getAge();
	std::cout << "Ability: " << std::endl;
	os << elf.getAbility();
	return os;
}
Elf& Elf::operator=(const Elf& elf)
{
	if (this != &elf)
	{
		delete[] name;
		size_t length = strlen(elf.name) + 1;
		this->name = new char[length];
		strcpy_s(this->name, length, elf.name);
		this->age = elf.getAge();
		this->ability = elf.getAbility();
	}
	return *this;
}