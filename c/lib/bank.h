#ifndef BANK_H
#define BANK_H

enum BankOperation
{
    InvalidOperation = 0, CreateAccount = 1, TransferFunds, Withdraw, CheckBalance
};

struct Bank;

enum BankOperation prompt_operation_selection();

/**
 * Accounts related operations
 */
void create_account();
void find_account();
void transfer_funds();
void check_account_balance();
void withdraw_funds();

/**
 *transaction related operations
 */
void create_transaction();
void get_account_transactions();


/**
 * Inter nal Calls
 */
void find_or_create_data_storage();
void save_changes();
void save_transactions();
#endif
