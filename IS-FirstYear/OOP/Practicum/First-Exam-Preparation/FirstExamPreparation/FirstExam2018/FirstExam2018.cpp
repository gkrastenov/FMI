#include <iostream>
#include "ElfTeam.h"

void analyse(const ElfTeam* teams, const int length)
{
	if (length == 0)
	{
		std::cout << "No teams for analyse" << std::endl;
		return;
	}
	ElfTeam team = ElfTeam(teams[0]);
	for (size_t i = 0; i < length; i++)
	{
		if (team < teams[i])
		{
			team = teams[i];
		}
	}

	// printing
	std::cout << "Best team is: " << std::endl;
	std::cout << team;
}
int main()
{
    std::cout << "Hello World!\n";
}