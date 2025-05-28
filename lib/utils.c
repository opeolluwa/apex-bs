#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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
    static char first_name[MAX_INPUT_CHARS + 1] = "";
    static char last_name[MAX_INPUT_CHARS + 1] = "";
    static char transaction_pin[5] = "";
    static bool first_name_edit_mode = false;
    static bool last_name_edit_mode = false;
    static bool transaction_pin_edit_mode = false;
    static int account_type = 0; // index: 0 = Savings, 1 = Current, 2 = Investment
    static bool dropdown_edit_mode = false;

    SetWindowTitle("Apex Bank PLC - Create account");

    GuiLabel((Rectangle){10, 45, WINDOW_WIDTH, 24}, "Input first name");
    GuiLabel((Rectangle){10, 104, WINDOW_WIDTH, 24}, "Input last name");
    GuiLabel((Rectangle){10, 162, WINDOW_WIDTH, 24}, "Choose an account type");
    GuiLabel((Rectangle){10, 217, WINDOW_WIDTH, 24}, "Input transaction pin");


    const Rectangle firstNameBox = {10, 69, (WINDOW_WIDTH * 0.95f), ELEMENT_HEIGHT};
    const Rectangle lastNameBox = {10, 128, (WINDOW_WIDTH * 0.95f), ELEMENT_HEIGHT};
    const Rectangle dropdownBox = {10, 187, (WINDOW_WIDTH * 0.95f), ELEMENT_HEIGHT};
    const Rectangle transactionPinBox =
    {
        10, 241, (WINDOW_WIDTH * 0.95f), ELEMENT_HEIGHT
    };

    if (GuiTextBox(firstNameBox, first_name, MAX_INPUT_CHARS, first_name_edit_mode))
    {
        first_name_edit_mode = !first_name_edit_mode;
    }

    if (GuiTextBox(lastNameBox, last_name, MAX_INPUT_CHARS, last_name_edit_mode))
    {
        last_name_edit_mode = !last_name_edit_mode;
    }

    if (GuiDropdownBox(dropdownBox, "Savings;Current;Investment", &account_type, dropdown_edit_mode))
    {
        dropdown_edit_mode = !dropdown_edit_mode;
    }

    if (GuiTextBox(transactionPinBox, transaction_pin, 5, transaction_pin_edit_mode))
    {
        transaction_pin_edit_mode = !transaction_pin_edit_mode;
    }


    if (GuiButton((Rectangle){10, 280, WINDOW_WIDTH * 0.95, 24}, GuiIconText(ICON_ARROW_RIGHT, "Create account")))
    {
        printf("%s %s %s %d", first_name, last_name, transaction_pin, account_type);
    }
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
