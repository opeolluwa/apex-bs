#include <stdio.h>
#include "bank.h"
#include "account.h"
#include <sqlite3.h>


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
        return WithdrawFunds;
    case 4:
        return CheckBalance;
    default:
        return -1;
    }
}


void process_selection(const enum BankOperation selected_operation, sqlite3* database)
{
    switch (selected_operation)
    {
    case CreateAccount:
        create_account(database);
        break;
    default:
        printf("the selected operation is %d", selected_operation);
    }
}


void create_account(sqlite3* database)
{
    const Account account = __create_account();
    const char
        * query =
            "INSERT INTO accounts(identifier, first_name, last_name, transaction_pin, account_number, account_balance) VALUES (?,?,?,?,?,?)";

    sqlite3_stmt* stmt;
    char* err_msg;

    int rc = sqlite3_prepare_v2(database, query, -1, &stmt, NULL);
    if (rc != SQLITE_OK) fprintf(stderr, "account creation failed due to %s", sqlite3_errmsg(database));


    // bind the values
    sqlite3_bind_text(stmt, 1, account.identifier, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, account.first_name, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, account.last_name, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, account.transaction_pin, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, account.account_number, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 6, 0, -1, SQLITE_STATIC);


    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) fprintf(stderr, "Execution failed: %s\n", sqlite3_errmsg(database));
    else printf("Account created successfully.\n");
}
