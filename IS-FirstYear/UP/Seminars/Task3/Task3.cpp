// Task3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <thread>         
#include <chrono>   

using namespace std;

string commands[8];
double seconds;
int numberOfCommands = 0;

bool setNumerOfCommands(string condition)
{
	if (condition == "easy")
	{
		numberOfCommands = 4;
		return true;
	}
	if (condition == "medium")
	{
		numberOfCommands = 6;
		return true;

	}
	if (condition == "hard")
	{
		numberOfCommands = 8;
		return true;

	}
	return false;
}
void setCommandsByCondition(string condition)
{
	commands[0] = "up";
	commands[1] = "left";
	commands[2] = "down";
	commands[3] = "right";

	if (condition == "medium")
	{
		commands[4] = "duck";
		commands[5] = "jump";
		return;
	}

	if (condition == "hard")
	{
		commands[4] = "duck";
		commands[5] = "jump";
		commands[6] = "walk";
		commands[7] = "hit";
	}
}
void setTimeDuration(string condition)
{
	if (condition == "easy")
	{
		seconds = 1;
	}
	if (condition == "medium")
	{
		seconds = 0.5;
	}
	if (condition == "hard")
	{
		seconds = 0.25;
	}
}

string generateRandomCommand()
{
	int randomIndex= rand() % numberOfCommands;
	return commands[randomIndex];
}
int main()
{
    string condition;
    cin >> condition;
	int totalPoints = 0;
	bool correct = setNumerOfCommands(condition);
	if (correct == false)
	{
		cout << "Invalid condition, please try with easy, medium or hard" << endl;
	}
	else {
		setCommandsByCondition(condition);
		setTimeDuration(condition);

		cout << "Starting " << condition << " mode. You will have " << numberOfCommands << " states ( ";
		for (int i = 0; i < numberOfCommands; i++)
		{
			commands[i] = generateRandomCommand();
			if (numberOfCommands - 1 == i)
			{
				cout << commands[i] << ")";
				break;
			}
			cout << commands[i] << ", ";
		}
		cout << " and a period of " << seconds << " sec to look at the answers.";
		cout << "\n";

		string toContinue = "";
		string currentCommand = "";
		string arrComands[8];

		bool flag = true;
		while (toContinue != "No")
		{
			for (int i = 0; i < numberOfCommands; i++)
			{
				cout << "Simon say ";
				string currentCommand = generateRandomCommand();
				cout << currentCommand;
				this_thread::sleep_for(std::chrono::duration<double>(seconds));
				system("CLS");
				arrComands[i] = currentCommand;
			}
			system("CLS");
			cout << "Now it's your turn!";
			cout << "\n";


			// user input
			string inputArray[8];
			for (int i = 0; i < numberOfCommands; i++)
			{
				string input;
				cin >> input;
				if (input != arrComands[i])
				{
					flag = false;
					break;
				}
			}

			if (flag)
			{
				totalPoints++;
				cout << "Congrats! That's correct! You have " << totalPoints << " point up to now. Continue? (Yes/No)" << endl;;
				cin >> toContinue;
			}
			else {
				cout << "Sorry, you lost!You had " << totalPoints << " point before you lost." << endl;
				break;
			}
		}
	}
}
