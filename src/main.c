#include "raylib.h"
#include "map.h"
#include <stdlib.h>
#include <time.h>
#include "ghost.h"

#define CELL_SIZE 40
#define GHOST_COUNT 3
#define GHOST_DELAY 30

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

// Color of each ghost
static const Color GHOST_COLORS[] = { RED, PINK, SKYBLUE, ORANGE };

// Draws each ghost as a colored circle in the middle of its cell
static void draw_ghosts(const Ghost *ghosts, int count)
{
    for (int i = 0; i < count; i++)
    {
        DrawCircle(ghosts[i].pos.x * CELL_SIZE + CELL_SIZE / 2,
                    ghosts[i].pos.y * CELL_SIZE + CELL_SIZE / 2,
                    15, GHOST_COLORS[ghosts[i].id]);
    }
}

int main(void)
{
    InitWindow(800,600, "Pac-Man");
    SetTargetFPS(60);
    srand(time(NULL));

    Map map;
    map_init(&map);
    Ghost *ghosts = ghosts_create(GHOST_COUNT);
    if(ghosts == NULL)
    {
        CloseWindow();
        return 1;
    }

    int frame = 0;

    while(!WindowShouldClose()) 
    {
        frame++;
        if (frame % GHOST_DELAY == 0)
        {
            ghosts_move(ghosts, GHOST_COUNT, &map);
        }

        BeginDrawing();
        ClearBackground(BLACK);
        draw_map(&map);
        draw_ghosts(ghosts, GHOST_COUNT);
        EndDrawing();
    }

    ghosts_destroy(ghosts);
    CloseWindow();

    return 0;
}