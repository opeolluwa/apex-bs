#include <stdio.h>
#include "../include/uuidv4.h"

struct Account
{
    char identifier[36];
    double account_balance;
    char *first_name;
    char *last_name;
};


struct Account create_account()
{
    struct Account account;

    UUID4_STATE_T state;
    UUID4_T uuid;

    uuid4_seed(&state);
    uuid4_gen(&state, &uuid);

    printf("What is your first name?");
    scanf("%s", &account.first_name);
    printf("What is your first name?");
    scanf("%s", &account.last_name);
    account.account_balance = 0;
    uuid4_to_s(uuid, account.identifier, 36);

    return account;
}
