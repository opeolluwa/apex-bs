#include "include/libraygui/raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "include/libraygui/raygui.h"
#include "include/libraygui/style.h"
#include "lib/bank.h"
#include "lib/constants.h"
#include "lib/utils.h"

int main()
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Apex Bank PLC");
    SetTargetFPS(60);

    int selected_action = -1;
    int index_action = -1;

    GuiLoadStyleCyber();

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

        if (selected_action == -1)
        {
            GuiLabel((Rectangle){ELEMENT_SPACER, 10, WINDOW_WIDTH, 24}, "What would you like to do?");
            GuiListView((Rectangle){ELEMENT_SPACER, 60, (int)(WINDOW_WIDTH - ELEMENT_SPACER * 2), 150},
                        "> create account;> withdraw funds;> transfer funds;> make a complaint;> check balance",
                        &index_action, &selected_action);
        }
        else
        {
            switch (selected_action)
            {
            case CreateAccount:
                render_create_bank_view();
                break;
            case WithdrawFunds:
                render_withdraw_view();
                break;
            case TransferFunds:
                render_transfer_funds_view();
                break;
            case CheckBalance:
                render_check_balance_view();
                break;
            default:
                render_default_view();
                break;
            }
            if (GuiButton((Rectangle){10, 10, 90, 24}, GuiIconText(ICON_ARROW_LEFT, "GO BACK")))
            {
                selected_action = -1;
            }
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
