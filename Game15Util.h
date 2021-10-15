#ifndef GAME15_GAME15UTIL_H
#define GAME15_GAME15UTIL_H

#include "Game15Entities.h"
#include <stdlib.h>
#include <time.h>

void swap_values(int* a, int* b);

void shuffle_field(Game15Field* field);

Game15Field create_field();

void make_turn_game(Game15Field* field, Game15Direction direction);

int is_end_game(Game15Field field);

#endif //GAME15_GAME15UTIL_H

