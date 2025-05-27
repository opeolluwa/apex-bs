#ifndef BANK_H
#define BANK_H

enum BankOperation
{
    CreateAccount = 0, WithdrawFunds = 1, TransferFunds = 2, MakeComplaint = 3, CheckBalance = 4
};

enum Language
{
    English,
    French
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
 * Internal Calls
 */
void find_or_create_data_storage();
void save_changes();
void save_transactions();
void process_selection(enum BankOperation selected_operation);

#endif
