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
    bool secret_view_active = true;
    GuiLabel((Rectangle){10, VERTICAL_POSITION, WINDOW_WIDTH, 24}, "Welcome to account creation");

    // GuiTextInputBox((Rectangle){10, VERTICAL_POSITION * 2, (WINDOW_WIDTH * 0.65), (float)ELEMENT_HEIGHT}, "",
    //                 "input your first name",
    //                 "", "", 100, &secret_view_active);

    GuiTextBox((Rectangle){10, VERTICAL_POSITION * 2, (WINDOW_WIDTH * 0.95), (float)ELEMENT_HEIGHT},
               "Enter your first name", 99, false);

    GuiTextBox((Rectangle){10, VERTICAL_POSITION * 3, (WINDOW_WIDTH * 0.95), (float)ELEMENT_HEIGHT},
               "Enter your last name", 99, false);
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
