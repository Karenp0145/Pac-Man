#include "raylib.h"
#include "map.h"

#define CELL_SIZE 40

//Draws the wall and dots of the map
static void draw_map(const Map *map){
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            if (map->cells[y][x] == '.')
            {
                DrawCircle(x * CELL_SIZE + CELL_SIZE / 2,
                                y * CELL_SIZE + CELL_SIZE / 2,
                                4, WHITE);
            } else if (map->cells[y][x] == '#') {
                DrawRectangle(x * CELL_SIZE, y * CELL_SIZE,
                                    CELL_SIZE, CELL_SIZE, BLUE);
            }
        }
    }
}

int main(void)
{
    InitWindow(800,600, "Pac-Man");
    SetTargetFPS(60);

    Map map;
    map_init(&map);

    while(!WindowShouldClose()) 
    {
        BeginDrawing();
        ClearBackground(BLACK);
        draw_map(&map);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}