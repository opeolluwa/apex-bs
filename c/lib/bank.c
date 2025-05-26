#include <stdio.h>
#include "bank.h"
#include "account.h"

struct Bank
{
    //storage
    //accounts -> pointer to storage.accounts
    //transactions -> pointer to storage.accounts
};

enum BankOperation prompt_operation_selection()
{
    int operation;
    printf(
        "Please select an operation\n1 -> Create account\n2 -> Transfer funds\n3 -> Withdraw\n4 -> Check balance \n>>");
    scanf("%d", &operation);
    switch (operation)
    {
    case 1:
        return CreateAccount;
    case 2:
        return TransferFunds;
    case 3:
        return Withdraw;
    case 4:
        return CheckBalance;
    default:
        return InvalidOperation;
    }
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


void create_account()
{
    __create_account();
}
