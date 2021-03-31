#include <iostream>
#include "BankAccount.h"

using namespace std;
int main()
{
    BankAccount firstAccount = BankAccount();
    firstAccount.setAccountnum("setAccountnum");
    firstAccount.setName("Name");
    firstAccount.setBalance(200);

    BankAccount secondAccount = BankAccount(firstAccount);
    BankAccount thirdAccount = firstAccount;
}
