
#ifndef GAME15_GAME15ENTITIES_H
#define GAME15_GAME15ENTITIES_H

/*
 * Ширина поля
 */
#define FIELD_WIDTH 4

/*
 * Высота поля
 */
#define FIELD_HEIGHT 4

/*
 * struct:  Game15Field
 * --------------------
 * Структура игрового поля
 *
 *  cells: массив игровых клеток
 */
typedef struct Game15Field
{
    int cells[FIELD_WIDTH][FIELD_HEIGHT];
} Game15Field;

/*
 * enum:  Game15Direction
 * --------------------
 * Константы направления
 *
 *  UP: вверх
 *  DOWN: вниз
 *  LEFT: влево
 *  RIGHT: вправо
 */
typedef enum Game15Direction
{
    UP, DOWN, LEFT, RIGHT
} Game15Direction;

#endif //GAME15_GAME15ENTITIES_H

