#ifndef TYPES_H
#define TYPES_H

// Position of an element on the map grid.
typedef struct
{
    int x;
    int y;
}Position;

// Direction in which a character moves.
typedef enum {
    DIR_NONE,
    DIR_LEFT,
    DIR_RIGHT,
    DIR_UP, 
    DIR_DOWN
}Direction;

#endif
