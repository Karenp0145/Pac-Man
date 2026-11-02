#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"
#include "map.h"   // doit définir MAP_WIDTH, MAP_HEIGHT et le tableau map

typedef struct {
    Position  pos;      // case actuelle
    Direction dir;      // direction actuelle
    Direction nextDir;  // direction demandée par le joueur
} Player;

void player_init(Player *p, int x, int y);
void player_set_direction(Player *p, Direction d);
void player_update(Player *p, char map[MAP_HEIGHT][MAP_WIDTH]);

#endif