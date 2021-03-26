#include "BattleShip.h"
#include<iostream>
#include <typeinfo>

using namespace std;
template<class T>
BattleShip<T>::BattleShip()
{
	this->speed = 0;
	this->weapons = 0;
	this->hyperJump = false;
	this->size = 0;
	this->pilot = nullptr;
}


template<class T>
BattleShip<T>::BattleShip(const BattleShip& battleShip)
{
	if (isValidType())
	{
		setSpeed(battleShip.speed);
		setWeapons(battleShip.weapons);
		setHyperJump(battleShip.hyperJump);
		setSize(battleShip.size);
		setPilot(battleShip.pilot);
	}
	else {
		printInvalidTypeMessage();
	}

}

template<class T>
BattleShip<T>::BattleShip(const int speed, const int weapons, const bool hyperJump,
	const int size, const T& pilot)
{
	if (isValidType())
	{
		setSpeed(speed);
		setWeapons(weapons);
		setHyperJump(hyperJump);
		setSize(size);
		setPilot(pilot);
	}
	else {
		printInvalidTypeMessage();
	}
}

template<class T>
BattleShip<T>::~BattleShip()
{
	this->speed = 0;
	this->weapons = 0;
	this->hyperJump = false;
	this->size = 0;
	this->pilot = nullptr;
}

template<class T>
void BattleShip<T>::setSpeed(const int speed) {
	this->speed = speed
}

template<class T>
void BattleShip<T>::setWeapons(const int weapons) {
	this->weapons = weapons
}

template<class T>
void BattleShip<T>::setHyperJump(const bool hyperJump) {
	this->hyperJump = hyperJump
}

template<class T>
void BattleShip<T>::setSize(const int size) {
	this->size = size
}

template<class T>
void BattleShip<T>::setPilot(const T pilot) {
	if (isValidType())
	{
		this->pilot = pilot;
	}
	else {
		printInvalidTypeMessage();
	}
}
template<class T>

void BattleShip<T>::printInvalidTypeMessage() {
	std::cout << "Invalid type" << std::endl;
}

template<class T>
bool BattleShip<T>::isValidType() {
	char* type = typeid(this).name();
	if (std::strcmp(type, "Jedi") == 0 || std::strcmp(type, "Stormtrooper"))
		return true;

	return false;
}

template<class T>
char* BattleShip<T>::getType() {
	char* type = typeid(this).name();
	return type;
}

