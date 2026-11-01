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

bool map_is_wall(const Map *map, Position pos)
{
    if (pos.x < 0 || pos.x >= MAP_WIDTH || pos.y < 0 || pos.y >= MAP_HEIGHT ){
        return true;
    }


    return (map-> cells[pos.y][pos.x] == '#');
}