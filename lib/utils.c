#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include "../include/libraygui/raygui.h"
#include "constants.h"

#define MAX_INPUT_CHARS 99

bool confirm_further_operation()
{
    char selection;
    printf("Do you want to perform another transaction y/n?");
    scanf("%s", &selection);
    return tolower(selection) == 'y';
}


void render_create_bank_view(void)
{
    char first_name[MAX_INPUT_CHARS + 1] = "\0";
    int account_type = 1;

    SetWindowTitle("Apex Bank PLC - Create account");

    GuiTextBox((Rectangle){
                   10, VERTICAL_POSITION * 1.5, (WINDOW_WIDTH * 0.95), (float)ELEMENT_HEIGHT
               },
               "enter your first name", 99, false);

    GuiTextBox((Rectangle){10, VERTICAL_POSITION * 2.5, (WINDOW_WIDTH * 0.95), (float)ELEMENT_HEIGHT},
               "Enter your last name", 99, false
    );

    GuiDropdownBox((Rectangle){10, VERTICAL_POSITION * 3.5, (WINDOW_WIDTH * 0.95), (float)ELEMENT_HEIGHT},
                   "Savings;current;investment", &account_type, false);
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
