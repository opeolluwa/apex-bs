#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

bool confirm_further_operation();

void render_create_bank_view(void);
void render_transfer_funds_view(void);
void render_withdraw_view(void);
void render_check_balance_view(void);
void render_default_view(void);

#endif
