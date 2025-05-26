#include <stdio.h>
enum BankOperation
{
    InvalidOperation = 0, CreateAccount = 1, TransferFunds, Withdraw, CheckBalance
};

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
