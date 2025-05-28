#include <stdbool.h>
#include "lib/utils.h"
#include "lib/bank.h"
#include <sqlite3.h>
#include <stdio.h>

bool perform_more_transaction = false;

int main(void)
{
    sqlite3* database;
    int rc = sqlite3_open("apex.db", &database);
    if (rc != SQLITE_OK)
    {
        printf("Error opening database file due to %s", sqlite3_errmsg(database));
    }
    else
    {
        fprintf(stdout, "Database connection successfully established\n");
    };

    const char* query =
        "CREATE TABLE IF NOT EXISTS accounts ("
        "identifier CHAR(36) PRIMARY KEY,"
        "account_number CHAR(10),"
        "first_name TEXT, "
        "email, "
        "last_name TEXT,"
        "transaction_pin CHAR(4),"
        "account_balance REAL);"

        "CREATE TABLE IF NOT EXISTS transactions("
        "identifier CHAR(36) PRIMARY KEY,"
        "sender_account_identifier CHAR(36),"
        "recipient_account_identifier CHAR(36),"
        "description TEXT,"
        "transaction_date TEXT);";

    char* err_message;
    rc = sqlite3_exec(database, query, 0, 0, &err_message);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Error opening database file due to %s", sqlite3_errmsg(database));
        sqlite3_free(err_message);
        sqlite3_close(database);
        return 1;
    }

    do
    {
        const enum BankOperation selected_operation = prompt_operation_selection();
        process_selection(selected_operation, database);

        const bool selection = confirm_further_operation();
        perform_more_transaction = selection;
    }
    while (perform_more_transaction != false);

    sqlite3_close(database);
    return 0;
}
