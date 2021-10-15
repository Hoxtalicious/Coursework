
#include "Game15GUI.h"

void display_game_field(Game15Field field)
{
    printf("X-------------------X\n");
    printf("|       15 GAME     |\n");
    printf("X---- ---- ---- ----X\n");
    for(int i=0;i<FIELD_WIDTH;i++)
    {
        for(int j=0;j<FIELD_HEIGHT;j++)
        {
            if(field.cells[i][j] != 0)
            {
                printf("| %2d ", field.cells[i][j]);
            }
            else
            {
                printf("|    ");
            }
        }
        printf("|\n");
        printf("X---- ---- ---- ----X\n");
    }
    printf("| Manual :          |\n");
    printf("|-------------------|\n");
    printf("| w - UP            |\n");
    printf("| s - DOWN          |\n");
    printf("| a - LEFT          |\n");
    printf("| d - RIGHT         |\n");
    printf("| q - EXIT          |\n");
    printf("| r - RESTART       |\n");
    printf("X---- ---- ---- ----X\n");
}

void display_logo()
{
    printf("X-----------------------------------------------------------------------------X\n");
    printf("X                                                                             X\n");
    printf("X        **    *****        ********       *          *       *     *****     X\n");
    printf("X       * *    *            *             * *        * *     * *    *         X\n");
    printf("X      *  *    *****        *  *****     *   *      *   *   *   *   *****     X\n");
    printf("X         *        *        *      *    *******    *     * *     *  *         X\n");
    printf("X       ****   *****        ********   *       *  *       *       * *****     X\n");
    printf("X                                                                             X\n");
    printf("X-----------------------------------------------------------------------------X\n");
}

void display_win()
{
    printf("X-----------------------------------------------------------------------------X\n");
    printf("X                                                                             X\n");
    printf("X                   *             *    *****   *     *                        X\n");
    printf("X                    *     *     *       *     * *   *                        X\n");
    printf("X                     *   * *   *        *     *  *  *                        X\n");
    printf("X                      * *   * *         *     *   * *                        X\n");
    printf("X                       *     *        *****   *     *                        X\n");
    printf("X                                                                             X\n");
    printf("X-----------------------------------------------------------------------------X\n");
}
