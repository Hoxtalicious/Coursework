#ifndef GAME15_GAME15UTIL_H
#define GAME15_GAME15UTIL_H

#include "Game15Entities.h"
#include <stdlib.h>
#include <time.h>

/*
 * Function:  swap
 * --------------------
 * Меняет местами значения двух переменнх
 *
 *  a: указатель на первое значение
 *  b: указатель на второе значение
 */
void swap_values(int* a, int* b);

/*
 * Function:  shuffle_field
 * --------------------
 * Перемешивает ячейки игрового поля
 *
 *  field: указатель на игровое поле
 */
void shuffle_field(Game15Field* field);

/*
 * Function:  create_field
 * --------------------
 * Создает новое, уже перемешанное, игровое поле
 *
 *  returns: игровое поле
 */
Game15Field create_field();

/*
 * Function:  make_turn_game
 * --------------------
 * Применяет ход в нужном направлении
 *
 *  field: указатель на игровое поле
 *  direction: направление хода
 */
void make_turn_game(Game15Field* field, Game15Direction direction);

/*
 * Function:  is_end_game
 * --------------------
 * Проверяет на конец игры
 *
 *  field: игровое поле
 *
 *  returns:
 *      1 - если игра окончена
 *      0 - иначе
 */
int is_end_game(Game15Field field);

#endif //GAME15_GAME15UTIL_H

