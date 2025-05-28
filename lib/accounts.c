#include <stdio.h>
#include "../include/uuidv4.h"
#include "account.h"


Account __create_account()
{
    Account account;

    UUID4_STATE_T state;
    UUID4_T uuid;

    uuid4_seed(&state);
    uuid4_gen(&state, &uuid);

    printf("What is your first name? ");
    scanf("%99s", account.first_name);
    printf("What is your last name? ");
    scanf("%99s", account.last_name);
    printf("Choose a 4 digit transaction pin ");
    scanf("%4s", account.transaction_pin);
    account.account_balance = 0;
    uuid4_to_s(uuid, account.identifier, 36);

    printf("%s  %s %s %s", account.first_name, account.last_name, account.transaction_pin, account.identifier);
    return account;
}
