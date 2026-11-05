/******************************************************************************/
/*                                                     .##################.   */
/*                                                     ##############   ###   */
/*   player.c                                          ##############   ###   */
/*                                                     ########'        ###   */
/*   By: etienne <etienne@ecole-decode.fr>             ######'  .###.   ###   */
/*                                                     ######   #####   ###   */
/*   Created: 2026/11/04 11:26:43 by etienne           ##   #.  '###'   ###   */
/*   Updated: 2026/11/04 12:43:13 by etienne           ##   ###.        ###   */
/*                                                     '##################'   */
/******************************************************************************/

#include "player.h"
#include "map.h"
#include "raylib.h"
#include <math.h>

#define TILE_SIZE  44
#define MOVE_DELAY 0.15f

void player_init(Player *p, int x, int y)
{
    p->pos.x = x;
    p->pos.y = y;
    p->dir = DIR_NONE;
    p->nextDir = DIR_NONE;
    p->timer = 0.0f;
}

static Position next_position(Position pos, Direction dir)
{
    switch (dir) {
        case DIR_LEFT:  pos.x--; break;
        case DIR_RIGHT: pos.x++; break;
        case DIR_UP:    pos.y--; break;
        case DIR_DOWN:  pos.y++; break;
        default: break;
    }
    if (pos.x < 0) pos.x = MAP_WIDTH - 1;
    else if (pos.x >= MAP_WIDTH) pos.x = 0;
    return pos;
}

static int is_free(Position pos, const Map *map)
{
    if (pos.y < 0 || pos.y >= MAP_HEIGHT) return 0;
    return map->cells[pos.y][pos.x] != '#';
}

void player_update(Player *p, const Map *map)
{
    // Touches
    if (IsKeyDown(KEY_LEFT)  || IsKeyDown(KEY_A)) p->nextDir = DIR_LEFT;
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) p->nextDir = DIR_RIGHT;
    if (IsKeyDown(KEY_UP)    || IsKeyDown(KEY_W)) p->nextDir = DIR_UP;
    if (IsKeyDown(KEY_DOWN)  || IsKeyDown(KEY_S)) p->nextDir = DIR_DOWN;

    // Déplacement à intervalle fixe
    p->timer += GetFrameTime();
    if (p->timer < MOVE_DELAY) return;
    p->timer -= MOVE_DELAY;

    if (p->nextDir != DIR_NONE && is_free(next_position(p->pos, p->nextDir), map))
        p->dir = p->nextDir;

    if (p->dir != DIR_NONE) {
        Position next = next_position(p->pos, p->dir);
        if (is_free(next, map))
            p->pos = next;
    }
}

void player_draw(const Player *p)
{
    Vector2 c = {
        p->pos.x * TILE_SIZE + TILE_SIZE / 2.0f,
        p->pos.y * TILE_SIZE + TILE_SIZE / 2.0f
    };
    float angle = 0.0f;
    if (p->dir == DIR_DOWN) angle = 90.0f;
    else if (p->dir == DIR_LEFT) angle = 180.0f;
    else if (p->dir == DIR_UP) angle = 270.0f;

    float mouth = 20.0f + 20.0f * sinf((float)GetTime() * 12.0f);
    DrawCircleSector(c, TILE_SIZE / 2.0f - 2, angle + mouth, angle + 360.0f - mouth, 32, YELLOW);
}