#ifndef BANK_H
#define BANK_H

enum BankOperation
{
    InvalidOperation = 0, CreateAccount = 1, TransferFunds, Withdraw, CheckBalance
};

struct Bank;

enum BankOperation prompt_operation_selection();

#endif
