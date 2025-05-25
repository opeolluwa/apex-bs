#include <stdio.h>

enum BankOperation
{
    CreateAccount, TransferFunds, Withdraw, CheckBalance
};

struct Bank
{
};


struct Account
{
    double account_balance;
    char first_name[20];
    char last_name[20];
};


int main()
{
    printf("hello world");
}
