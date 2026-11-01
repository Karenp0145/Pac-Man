#include <stdlib.h>
#include "ghost.h"


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