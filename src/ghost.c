#include <stdlib.h>
#include "ghost.h"

// Returns the cell next to pos in the given direction
static Position next_position(Position pos, Direction dir)
{
    if(dir == DIR_UP){
        pos.y -= 1;
    } else if (dir == DIR_DOWN) {
        pos.y += 1;
    } else if (dir == DIR_LEFT) {
        pos.x -= 1;
    } else if (dir == DIR_RIGHT) {
        pos.x += 1;
    }

    return pos;
}

// Returns the opposite direction (used to avoid U-turns)
static Direction opposite(Direction dir)
{
    if (dir == DIR_UP) return DIR_DOWN;
    if (dir == DIR_DOWN) return DIR_UP;
    if (dir == DIR_LEFT) return DIR_RIGHT;
    if (dir == DIR_RIGHT) return DIR_LEFT;
    return DIR_NONE;
}

// Returns a random direction: left, right, up or down
static Direction random_direction(void)
{
    return rand() % 4 + 1;
}

// Creates count ghosts with malloc and places them in the starting area
Ghost *ghosts_create(int count)
{
    Ghost *ghosts = malloc(count * sizeof(Ghost));
    if (ghosts == NULL) {
        return NULL;
    }

    for (int i = 0; i < count; i++)
    {
        ghosts[i].pos.x = 8 + i;
        ghosts[i].pos.y = 7;
        ghosts[i].dir = DIR_UP;
        ghosts[i].id = i;
    }
    return ghosts;
}

// Frees the memory of the ghosts
void ghosts_destroy(Ghost *ghosts)
{
    free(ghosts);
}


// Moves each ghost one cell forward
void ghosts_move(Ghost *ghosts, int count, const Map *map)
{
    for (int i = 0; i < count; i++) 
    {
        // Sometimes try to turn at a crossroads
        if (rand() % 3 == 0)
        {
            Direction d = random_direction();
            if (d != opposite(ghosts[i].dir) && !map_is_wall(map, next_position(ghosts[i].pos, d)))
            {
                ghosts[i].dir = d;
            }
        }
        Position next = next_position(ghosts[i].pos, ghosts[i].dir);
        
        while (map_is_wall(map, next))
            {
                ghosts[i].dir = random_direction();
                next = next_position(ghosts[i].pos, ghosts[i].dir);
            }
        ghosts[i].pos = next;
    }

}