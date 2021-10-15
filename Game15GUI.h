
#ifndef GAME15_GAME15GUI_H
#define GAME15_GAME15GUI_H

#include "stdio.h"
#include "Game15Entities.h"

/*
 * Function:  display_game_field
 * --------------------
 * Вывод игрового поля в консоль
 *
 *  field: объект игрового поля
 */
void display_game_field(Game15Field field);

/*
 * Function:  display_logo
 * --------------------
 * Вывод игрового лого
 */
void display_logo();

/*
 * Function:  display_win
 * --------------------
 * Вывод экрана об окончании игры
 */
void display_win();

#endif //GAME15_GAME15GUI_H

