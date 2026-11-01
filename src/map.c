#include <string.h>
#include "map.h"

// Level layout: '#' = wall, '.' = dot, ' ' = empty cell
static const char LAYOUT[MAP_HEIGHT][MAP_WIDTH + 1] = {
    "####################",
    "#........##........#",
    "#.##.###.##.###.##.#",
    "#..................#",
    "#.##.#.######.#.##.#",
    "#....#...##...#....#",
    "####.###.##.###.####",
    "#.......    .......#",
    "####.#.##  ##.#.####",
    "#....#.######.#....#",
    "#.##.....##.....##.#",
    "#..#.###.##.###.#..#",
    "##.#............#.##",
    "#....##.####.##....#",
    "####################"
};

// Sets up the map for a new game: copies the maze and counts the dots
void map_init(Map *map)
{
    map->dots_left = 0;

    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        strcpy(map->cells[y], LAYOUT[y]);
        for (int x = 0; x < MAP_WIDTH; x++)
        {
            if (map->cells[y][x] == '.')
            {
                map->dots_left += 1;
            }
        }
    }
}


// Returns true if the cell at pos is a wall or outside the map
// Checking the limits first prevents reading outside the array
bool map_is_wall(const Map *map, Position pos)
{
    if (pos.x < 0 || pos.x >= MAP_WIDTH || pos.y < 0 || pos.y >= MAP_HEIGHT ){
        return true;
    }
    return (map->cells[pos.y][pos.x] == '#');
}


// Returns true if a dot was eaten (so the game can add points)
// Removes the dot at pos if there is one, and updates dots_left
bool map_eat_dot(Map *map, Position pos)
{
    if (map->cells[pos.y][pos.x] == '.')
    {
        map->cells[pos.y][pos.x] = ' ';
        map->dots_left -= 1;
        return true;
    }

    return false;
}