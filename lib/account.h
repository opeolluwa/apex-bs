#ifndef ACCOUNT_H
#define ACCOUNT_H
#include  "../include/libbcrypt/bcrypt.h"

struct Account
{
    char identifier[36];
    float account_balance;
    char first_name[100];
    char last_name[100];
    char transaction_pin[BCRYPT_HASHSIZE];
    char account_number[11];
    char email[100];
};


struct Account __create_account();

typedef struct Account Account;

#endif
