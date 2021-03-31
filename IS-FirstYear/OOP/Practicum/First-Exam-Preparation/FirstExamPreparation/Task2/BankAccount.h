#pragma once
class BankAccount {
private:
    char* name;
    char* accountnum;
    double balance;
public:
    BankAccount();
    BankAccount(const BankAccount& account);
    ~BankAccount();

    BankAccount& operator=(const BankAccount& account);

    void setName(const char* name);
    void setAccountnum(const char* accountnum);
    void setBalance(const double balance);
};
