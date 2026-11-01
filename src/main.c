#include "raylib.h"

int main(void)
{
    InitWindow(800,600, "Pac-Man");
    SetTargetFPS(60);

    while(!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}