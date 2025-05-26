#include <stdbool.h>
#include "lib/utils.h"
// #include "lib/bank.h"

bool perform_more_transaction = false;

int main(int argc, char* argv[])
{
    while (perform_more_transaction != false)
    {
        const enum BankOperation selected_operation = prompt_operation_selection();
        process_selection(selected_operation);

       const bool selection = confirm_further_operation();
        perform_more_transaction = selection;
    }
}
