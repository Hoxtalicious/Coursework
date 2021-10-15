#include "Game15Util.h"

void swap_values(int* a, int* b)
{
    int buffer = *a;
    *a = *b;
    *b = buffer;
}

void shuffle_field(Game15Field* field)
{
    for (int i = 0; i < FIELD_HEIGHT; ++i)
    {
        for (int j = 0; j < FIELD_WIDTH; ++j)
        {
            swap_values(&field->cells[i][j],
                 &field->cells[rand() % FIELD_HEIGHT][rand() % FIELD_WIDTH]);
        }
    }
}

Game15Field create_field()
{
    Game15Field field;
    int counter = 0;

    for (int i=0;i<FIELD_HEIGHT;i++)
    {
        for(int j=0;j<FIELD_WIDTH;j++)
        {
            field.cells[i][j] = counter++;
        }
    }

    shuffle_field(&field);

    return field;
}

void make_turn_game(Game15Field* field, Game15Direction direction)
{
    int emptyCellI = -1;
    int emptyCellJ = -1;

    for (int i=0;i<FIELD_HEIGHT;i++)
    {
        for(int j=0;j<FIELD_WIDTH;j++)
        {
            if(field->cells[i][j] == 0)
            {
                emptyCellI = i;
                emptyCellJ = j;
                break;
            }
        }
    }

    if(emptyCellI == -1 || emptyCellJ == -1)
        return;

    switch (direction)
    {
        case UP: {
            if(emptyCellI < FIELD_HEIGHT - 1)
            {
                swap_values(&field->cells[emptyCellI][emptyCellJ],
                     &field->cells[emptyCellI+1][emptyCellJ]);
            }
            break;
        }
        case DOWN: {
            if(emptyCellI > 0)
            {
                swap_values(&field->cells[emptyCellI][emptyCellJ],
                     &field->cells[emptyCellI-1][emptyCellJ]);
            }
            break;
        }
        case LEFT: {
            if(emptyCellJ < FIELD_WIDTH - 1)
            {
                swap_values(&field->cells[emptyCellI][emptyCellJ],
                     &field->cells[emptyCellI][emptyCellJ+1]);
            }
            break;
        }
        case RIGHT: {
            if(emptyCellJ > 0)
            {
                swap_values(&field->cells[emptyCellI][emptyCellJ],
                     &field->cells[emptyCellI][emptyCellJ-1]);
            }
            break;
        }
    }
}

int is_end_game(Game15Field field)
{
    int counter = 1;

    if(field.cells[FIELD_HEIGHT-1][FIELD_WIDTH-1] != 0)
        return 0;

    for(int i=0;i<FIELD_HEIGHT;i++)
    {
        for(int j=0;j<FIELD_WIDTH;j++)
        {
            if(i != FIELD_HEIGHT - 1 || j != FIELD_WIDTH - 1)
            {
                if(counter++ != field.cells[i][j])
                    return 0;
            }
        }
    }

    return 1;
}
