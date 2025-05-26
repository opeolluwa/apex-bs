#include <stdio.h>
#include "../include/uuidv4.h"

struct Account
{
    char identifier[36];
    double account_balance;
    char first_name[100];
    char last_name[100];
};


struct Account create_account()
{
    struct Account account;

    UUID4_STATE_T state;
    UUID4_T uuid;

    uuid4_seed(&state);
    uuid4_gen(&state, &uuid);

    printf("What is your first name? ");
    scanf("%99s", account.first_name);
    printf("What is your last name? ");
    scanf("%99s", account.last_name);
    account.account_balance = 0;
    uuid4_to_s(uuid, account.identifier, 36);

    return account;
}
