#ifndef ACCOUNT_H
#define ACCOUNT_H


struct Account
{
    char identifier[36];
    double account_balance;
    char* first_name;
    char* last_name;
};


struct Account create_account();

#endif
