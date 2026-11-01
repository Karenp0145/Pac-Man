#ifndef GHOST_H
#define GHOST_H

#include "types.h"
#include "map.h"

// A ghost of the game
// pos: its current cell on the map
// dir: the direction it is moving in
// id: its number, used to choose its color when drawing
typedef struct
{
    Position pos;
    Direction dir;
    int id;
}Ghost;

// Creates count ghosts with malloc and places them in the starting area
Ghost *ghosts_create(int count);

// Frees the array of ghosts created by ghosts_create
void ghosts_destroy(Ghost *ghosts);

// Moves each ghost one cell. If a wall is ahead, it picks a new random direction
void ghosts_move(Ghost *ghosts, int count, const Map *map);

#endif