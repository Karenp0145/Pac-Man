#ifndef MAP_H
#define MAP_H

#include "types.h"
#include <stdbool.h>

// Map size
#define MAP_WIDTH 20
#define MAP_HEIGHT 15

//Game Map
//Cell can be a wall ('#'), a dot ('.') or empty (' ')
typedef struct
{
    char cells[MAP_HEIGHT][MAP_WIDTH + 1]; // +1 for the '\0'
    int dots_left;
}Map;

// Sets up the map for a new game: copies the maze and counts the dots
void map_init(Map *map);

//Return true if the cell at pos is  a wall or outside the map
bool map_is_wall(const Map *map, Position pos);

//Remove dot at pos if there is one
//Return true if a dot was eaten
bool map_eat_dot(Map *map, Position pos);

#endif