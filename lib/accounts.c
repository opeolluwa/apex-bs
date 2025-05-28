#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/uuidv4.h"
#include "account.h"
#include "../include/libbcrypt/bcrypt.h"

Account __create_account()
{
    Account account;
    char pin[5];

    UUID4_STATE_T state;
    UUID4_T uuid;

    uuid4_seed(&state);
    uuid4_gen(&state, &uuid);

    printf("What is your first name? ");
    scanf("%99s", account.first_name);
    printf("What is your last name? ");
    scanf("%99s", account.last_name);
    printf("Choose a 4 digit transaction pin ");
    scanf("%4s", pin);
    printf("Enter your email ");

    scanf("%99s", account.email);

    if (uuid4_to_s(uuid, account.identifier, UUID4_STR_BUFFER_SIZE) != true) fprintf(stderr, "error parsing uuid");

    const int work_factor = 12;
    char salt[BCRYPT_HASHSIZE];
    char hash[BCRYPT_HASHSIZE];

    int rc = bcrypt_gensalt(work_factor, salt);
    if (rc != 0) fprintf(stderr, "error creating account");

    rc = bcrypt_hashpw(pin, salt, hash);
    if (rc != 0) fprintf(stderr, "failed to hash password");

    account.account_balance = 0;
    snprintf(account.account_number, sizeof(account.account_number), "%010d", rand() % 1000000000);
    strcpy(account.transaction_pin, hash);
    return account;
}
