#pragma once
class Elf
{
private:
	const int MAX_AGE = 300;
	const int MIN_AGE = 1;
	const int MAX_ABILITY = 15;
	const int MIN_ABILITY = 1;

	char* name;
	int age;
	int ability;
public:
	Elf();
	Elf(const Elf& elf);
	Elf(const char* name, const int age, const int aiblity);
	~Elf();

	char* getName() const;
	int getAge() const;
	int getAbility() const;

	void setName(const char* name);
	void setAge(const int age);
	void setAbility(const int ability);

	Elf& operator=(const Elf& elf);
	friend std::ostream& operator<<(std::ostream& os, Elf& elf);
};

