// #include <stdbool.h>
// #include "lib/utils.h"
// #include "lib/bank.h"
//
// bool perform_more_transaction = false;
//
// int main(int argc, char* argv[])
// {
//     do
//     {
//         const enum BankOperation selected_operation = prompt_operation_selection();
//         process_selection(selected_operation);
//
//         const bool selection = confirm_further_operation();
//         perform_more_transaction = selection;
//     }
//     while (perform_more_transaction != false);
// }




#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#include "include/raygui.h"

int main()
{
    InitWindow(400, 200, "raygui - controls test suite");
    SetTargetFPS(60);

    bool showMessageBox = false;

    while (!WindowShouldClose())
    {
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));

        if (GuiButton((Rectangle){ 24, 24, 120, 30 }, "#191#Show Message")) showMessageBox = true;

        if (showMessageBox)
        {
            int result = GuiMessageBox((Rectangle){ 85, 70, 250, 100 },
                "#191#Message Box", "Hi! This is a message!", "Nice;Cool");

            if (result >= 0) showMessageBox = false;
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}