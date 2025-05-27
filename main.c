#include "include/libraygui/raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "include/libraygui/raygui.h"
#include "include/libraygui/style.h"
#include "lib/bank.h"
// #include  "include/libraygui/icon.h"

#define WINDOW_WIDTH 500
#define WINDOW_HEIGHT 500
#define ELEMENT_SPACER 10

void render_create_bank_view(void);
void render_transfer_funds_view(void);
void render_withdraw_view(void);
void render_check_balance_view(void);
void render_default_view(void);

int main()
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Apex Bank PLC");
    SetTargetFPS(60);

    bool showMessageBox = false;
    int selected_action = -1;
    int index_action = -1;

    GuiLoadStyleCyber();

    while (!WindowShouldClose())
    {
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));


        if (selected_action == -1)
        {
            GuiLabel((Rectangle){10, 10, WINDOW_WIDTH, 24}, "What would you like to do?");
            GuiListView((Rectangle){10, 60, (int)(WINDOW_WIDTH - ELEMENT_SPACER * 2), 200},
                        "> create account;> withdraw funds;> transfer funds;> make a complaint;> check balance",
                        &index_action, &selected_action);
        }


        if (selected_action == CreateAccount)
        {
            // GuiButton((Rectangle){10, 10, 50, 24}, "go back");
            GuiLabel((Rectangle){20, 10, WINDOW_WIDTH, 24}, "Welcome to account creation");
        }

        if (selected_action == WithdrawFunds)
        {
            // GuiButton((Rectangle){10, 10, 50, 24}, "go back");
            GuiLabel((Rectangle){10, 10, WINDOW_WIDTH, 24}, "Welcome to bank withdraw");
        }

        if (selected_action == TransferFunds)
        {
            if (GuiButton((Rectangle){10, 10, 90, 24}, GuiIconText(ICON_ARROW_LEFT, "GO BACK    ")))
            {
                selected_action = -1;
            }
            GuiLabel((Rectangle){10, 35, WINDOW_WIDTH, 24}, "Welcome to bank transfer");
        }

        if (selected_action == CheckBalance)
        {
            // GuiButton((Rectangle){10, 10, 50, 24}, "go back");
            GuiLabel((Rectangle){10, 10, WINDOW_WIDTH, 24}, "Welcome to bank check balance");
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}


void render_create_bank_view(void)
{
}

void render_transfer_funds_view(void)
{
}

void render_withdraw_view(void)
{
}

void render_check_balance_view(void)
{
}

void render_default_view(void)
{
}
