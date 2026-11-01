#include <stdlib.h>
#include "ghost.h"

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
        ghosts[i].u_turns = 0;
    }
    return ghosts;
}

void ghosts_destroy(Ghost *ghosts)
{
    free(ghosts);
}

void ghosts_move(Ghost *ghosts, int count, const Map *map)
{
    for (int i = 0; i < count; i++) 
    {
        Position next = next_position(ghosts[i].pos, ghosts[i].dir);
        
        while (map_is_wall(map, next))
            {
                ghosts[i].dir = random_direction();
                next = next_position(ghosts[i].pos, ghosts[i].dir);
            }
        ghosts[i].pos = next;
    }

}