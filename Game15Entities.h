
#ifndef GAME15_GAME15ENTITIES_H
#define GAME15_GAME15ENTITIES_H

#define FIELD_WIDTH 4

#define FIELD_HEIGHT 4

typedef struct Game15Field
{
    int cells[FIELD_WIDTH][FIELD_HEIGHT];
} Game15Field;

typedef enum Game15Direction
{
    UP, DOWN, LEFT, RIGHT
} Game15Direction;

#endif //GAME15_GAME15ENTITIES_H

