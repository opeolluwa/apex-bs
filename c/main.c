#include <stdbool.h>
#include "lib/bank.c"
#include "lib/utils.c"
#include "lib/transaction.c"
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
