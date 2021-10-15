#ifndef GAME15_GAME15UTIL_H
#define GAME15_GAME15UTIL_H

#include "Game15Entities.h"
#include <stdlib.h>
#include <time.h>

/*
 * Function:  swap
 * --------------------
 * ������ ������� �������� ���� ���������
 *
 *  a: ��������� �� ������ ��������
 *  b: ��������� �� ������ ��������
 */
void swap_values(int* a, int* b);

/*
 * Function:  shuffle_field
 * --------------------
 * ������������ ������ �������� ����
 *
 *  field: ��������� �� ������� ����
 */
void shuffle_field(Game15Field* field);

/*
 * Function:  create_field
 * --------------------
 * ������� �����, ��� ������������, ������� ����
 *
 *  returns: ������� ����
 */
Game15Field create_field();

/*
 * Function:  make_turn_game
 * --------------------
 * ��������� ��� � ������ �����������
 *
 *  field: ��������� �� ������� ����
 *  direction: ����������� ����
 */
void make_turn_game(Game15Field* field, Game15Direction direction);

/*
 * Function:  is_end_game
 * --------------------
 * ��������� �� ����� ����
 *
 *  field: ������� ����
 *
 *  returns:
 *      1 - ���� ���� ��������
 *      0 - �����
 */
int is_end_game(Game15Field field);

#endif //GAME15_GAME15UTIL_H

