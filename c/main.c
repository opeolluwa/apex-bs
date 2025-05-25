#include <stdio.h>
#include <stdbool.h>
#include  <ctype.h>

enum BankOperation
{
    InvalidOperation = 0, CreateAccount = 1, TransferFunds, Withdraw, CheckBalance
};

struct Bank
{
};


struct Account
{
    double account_balance;
    char first_name[20];
    char last_name[20];
};


enum BankOperation prompt_operation_selection()
{
    int8_t operation;
    printf(
        "Please select an operation\n1 ->Create account\n2 -> Transfer funds\n3 -> Withdraw\n4 -> Check balance ");
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

bool confirm_further_operation()
{
    char selection;
    printf("Do you want to perform another transaction y/n?");
    scanf("%s", &selection);
    return tolower(selection) == 'y';
}

void process_selection(enum BankOperation selected_operation)
{
    printf("the selected operation is %d", selected_operation);
}

bool perform_more_transaction = false;

int main(int argc, char* argv[])
{
    do
    {
        enum BankOperation selected_operation = prompt_operation_selection();
        prompt_operation_selection(selected_operation);

        bool selection = confirm_further_operation();
        perform_more_transaction = selection;
    }
    while (perform_more_transaction != false);
}
