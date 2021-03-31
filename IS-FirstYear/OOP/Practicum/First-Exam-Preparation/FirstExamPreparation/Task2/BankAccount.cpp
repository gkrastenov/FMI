#include "BankAccount.h"
#include<iostream>

BankAccount::BankAccount()
{
	this->name = nullptr;
	this->accountnum = nullptr;
	this->balance = 0;
}

BankAccount::BankAccount(const BankAccount& account)
{
	 setName(account.name);
	 setAccountnum(account.accountnum);
	 setBalance(account.balance);
}

BankAccount::~BankAccount()
{
	delete[] name;
	delete[] accountnum;

	this->name = nullptr;
	this->accountnum = nullptr;
	this->balance = 0;
}

BankAccount& BankAccount::operator=(const BankAccount& account) 
{
	if (this != &account)
	{
		delete[] name;
		delete[] accountnum;
		this->balance = 0;

		setName(account.name);
		setAccountnum(account.accountnum);
		setBalance(account.balance);
	}

	return *this;
}

void BankAccount::setName(const char* name)
{
	size_t lengthName = strlen(name) + 1;
	this->name = new char[lengthName];
	strcpy_s(this->name, lengthName, name);
}

void BankAccount::setAccountnum(const char* accountnum)
{
	size_t lengthAccountnum = strlen(accountnum) + 1;
	this->accountnum = new char[lengthAccountnum];
	strcpy_s(this->accountnum, lengthAccountnum, accountnum);
}

void BankAccount::setBalance(const double balance)
{
	this->balance = balance;
}