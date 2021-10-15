#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

extern "C"
{
#include "Game15Entities.h"
#include "Game15GUI.h"
#include "Game15Util.h"
}


int main()
{
    Game15Field field = create_field();
    int end = 0;

    display_logo();
    system("pause");

    while(!(end = is_end_game(field)))
    {
        system("cls");
        display_game_field(field);

        char move = (char)_getch();

        switch (move)
        {
            case 'w': make_turn_game(&field, UP); break;
            case 's': make_turn_game(&field, DOWN); break;
            case 'a': make_turn_game(&field, LEFT); break;
            case 'd': make_turn_game(&field, RIGHT); break;
            case 'q': goto exit; break;
            case 'r': shuffle_field(&field);
        }
    }

    if(end)
    {
        display_win();
    }

    exit: system("pause");

    return 0;
}
