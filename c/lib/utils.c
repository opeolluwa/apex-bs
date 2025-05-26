#include "bank.h"
#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include "account.h"
bool confirm_further_operation()
{
    char selection;
    printf("Do you want to perform another transaction y/n?");
    scanf("%s", &selection);
    return tolower(selection) == 'y';
}


void process_selection(const enum BankOperation selected_operation)
{
    switch (selected_operation)
    {
    case CreateAccount:
        create_account();
        break;
    default:
        printf("the selected operation is %d", selected_operation);
    }
}
