#ifndef ACCOUNT_H
#define ACCOUNT_H


struct Account
{
    char identifier[36];
    double account_balance;
    char first_name[100];
    char last_name[100];
    char transaction_pin[5];
    char account_number[11];
};


struct Account __create_account();

typedef struct Account Account;

#endif
