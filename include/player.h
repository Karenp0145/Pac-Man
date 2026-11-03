#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"

typedef struct {
    Position  pos;
    Direction dir;
    Direction nextDir;
    float     timer;   // pour avancer à vitesse régulière
} Player;

void player_init(Player *p, int x, int y);
void player_update(Player *p);   // lit les touches + déplace
void player_draw(const Player *p);

#endif