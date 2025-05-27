#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include "../include/libraygui/raygui.h"
#include "constants.h"


bool confirm_further_operation()
{
    char selection;
    printf("Do you want to perform another transaction y/n?");
    scanf("%s", &selection);
    return tolower(selection) == 'y';
}


void render_create_bank_view(void)
{
    GuiLabel((Rectangle){20, 35, WINDOW_WIDTH, 24}, "Welcome to account creation");
}

void render_transfer_funds_view(void)
{
    GuiLabel((Rectangle){10, 35, WINDOW_WIDTH, 24}, "Welcome to bank transfer");
}

void render_withdraw_view(void)
{
    GuiLabel((Rectangle){10, 35, WINDOW_WIDTH, 24}, "Welcome to bank withdraw");
}

void render_check_balance_view(void)
{
    GuiLabel((Rectangle){10, 35, WINDOW_WIDTH, 24}, "Welcome to bank check balance");
}

void render_default_view(void)
{
    GuiLabel((Rectangle){10, 35, WINDOW_WIDTH, 24}, "Unknown action selected.");
}

