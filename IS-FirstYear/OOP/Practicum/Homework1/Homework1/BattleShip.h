#pragma once
#include<iostream>


template<class T>
class BattleShip
{
private:
	int speed;
	int weapons;
	bool hyperJump;
	int size;
	T pilot;
public:
	BattleShip();
	BattleShip(const BattleShip& battleShip);
	BattleShip(const int speed, const int weapons, const bool hyperJump, const int size, const T& pilot);
	~BattleShip();

	void setSpeed(const int speed);
	void setWeapons(const int weapons);
	void setHyperJump(const bool hyperJump);
	void setSize(const int size);
	void setPilot(const T pilot);
	
	bool isValidType();
	char* getType()	
};



