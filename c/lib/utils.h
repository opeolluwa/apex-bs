#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
#include "bank.h"

bool confirm_further_operation();

void process_selection(enum BankOperation selected_operation);

#endif
