#include <gtest/gtest.h>

extern "C"
{
#include "Game15Util.h"
#include "Game15Entities.h"
}

namespace
{
    TEST(SwapTest, CheckValues)
    {
        int a = 5;
        int b = 10;

        int expectedA = 10;
        int expectedB = 5;

        swap_values(&a, &b);

        EXPECT_EQ(expectedA, a);
        EXPECT_EQ(expectedB, b);
    }
    
    TEST(ShuffleFieldTest, CheckShuffiling)
    {
        Game15Field field;

        int inc = 0;
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                field.cells[i][j] = inc++;

        shuffle_field(&field);

        inc = 0;

        bool isShuffeled = false;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(field.cells[i][j] != inc)
                {
                    isShuffeled = true;
                }
                inc++;
            }
        }

        EXPECT_EQ(true, isShuffeled);
    }

    TEST(CreateFieldTest, CheckIfFieldCreatingSuccessufully)
    {
        Game15Field field = create_field();

        bool passed = true;
        for(int k=0;k<16;k++)
        {
            bool isPresent = false;
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<4;j++)
                {
                    if(field.cells[i][j] == k)
                    {
                        isPresent = true;
                    }
                }
            }

            if(!isPresent)
            {
                passed = false;
                break;
            }
        }

        EXPECT_EQ(true, passed);
    }


    TEST(MoveTest, MoveUpAccepted)
    {
        int init[4][4] = {
            { 0, 1, 2, 3},
            { 4, 5, 6, 7},
            { 8, 9,10,11},
            {12,13,14,15}
        };

        int expected[4][4] = {
            { 4, 1, 2, 3},
            { 0, 5, 6, 7},
            { 8, 9,10,11},
            {12,13,14,15}
        };

        Game15Field field;

        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                field.cells[i][j] = init[i][j];
            }
        }

        make_turn_game(&field, UP);

        bool isPassed = true;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(field.cells[i][j] != expected[i][j])
                {
                    isPassed = false;
                }
            }
        }

        EXPECT_EQ(true, isPassed);
    }

    TEST(MoveTest, MoveUpDeclined)
    {
        int init[4][4] = {
            {12, 1, 2, 3},
            { 4, 5, 6, 7},
            { 8, 9,10,11},
            { 0,13,14,15}
        };

        int expected[4][4] = {
            {12, 1, 2, 3},
            { 4, 5, 6, 7},
            { 8, 9,10,11},
            { 0,13,14,15}
        };

        Game15Field field;

        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                field.cells[i][j] = init[i][j];
            }
        }

        make_turn_game(&field, UP);

        bool isPassed = true;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(field.cells[i][j] != expected[i][j])
                {
                    isPassed = false;
                }
            }
        }

        EXPECT_EQ(true, isPassed);
    }

    TEST(MoveTest, MoveDownAccepted)
    {
        int init[4][4] = {
            { 4, 1, 2, 3},
            { 0, 5, 6, 7},
            { 8, 9,10,11},
            {12,13,14,15}
        };

        int expected[4][4] = {
            { 0, 1, 2, 3},
            { 4, 5, 6, 7},
            { 8, 9,10,11},
            {12,13,14,15}
        };

        Game15Field field;

        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                field.cells[i][j] = init[i][j];
            }
        }

        make_turn_game(&field, DOWN);

        bool isPassed = true;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(field.cells[i][j] != expected[i][j])
                {
                    isPassed = false;
                }
            }
        }

        EXPECT_EQ(true, isPassed);
    }

    TEST(MoveTest, MoveDownDeclined)
    {
        int init[4][4] = {
            { 0, 1, 2, 3},
            { 4, 5, 6, 7},
            { 8, 9,10,11},
            {12,13,14,15}
        };

        int expected[4][4] = {
            { 0, 1, 2, 3},
            { 4, 5, 6, 7},
            { 8, 9,10,11},
            {12,13,14,15}
        };

        Game15Field field;

        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                field.cells[i][j] = init[i][j];
            }
        }

        make_turn_game(&field, DOWN);

        bool isPassed = true;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(field.cells[i][j] != expected[i][j])
                {
                    isPassed = false;
                }
            }
        }

        EXPECT_EQ(true, isPassed);
    }

    TEST(MoveTest, MoveLeftAccepted)
    {
        int init[4][4] = {
            { 4, 1, 2, 3},
            { 0, 5, 6, 7},
            { 8, 9,10,11},
            {12,13,14,15}
        };

        int expected[4][4] = {
            { 4, 1, 2, 3},
            { 5, 0, 6, 7},
            { 8, 9,10,11},
            {12,13,14,15}
        };

        Game15Field field;

        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                field.cells[i][j] = init[i][j];
            }
        }

        make_turn_game(&field, LEFT);

        bool isPassed = true;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(field.cells[i][j] != expected[i][j])
                {
                    isPassed = false;
                }
            }
        }

        EXPECT_EQ(true, isPassed);
    }

    TEST(MoveTest, MoveLeftDeclined)
    {
        int init[4][4] = {
            { 3, 1, 2, 0},
            { 4, 5, 6, 7},
            { 8, 9,10,11},
            {12,13,14,15}
        };

        int expected[4][4] = {
            { 3, 1, 2, 0},
            { 4, 5, 6, 7},
            { 8, 9,10,11},
            {12,13,14,15}
        };

        Game15Field field;

        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                field.cells[i][j] = init[i][j];
            }
        }

        make_turn_game(&field, LEFT);

        bool isPassed = true;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(field.cells[i][j] != expected[i][j])
                {
                    isPassed = false;
                }
            }
        }

        EXPECT_EQ(true, isPassed);
    }

    TEST(MoveTest, MoveRightAccepted)
    {
        int init[4][4] = {
            { 4, 1, 2, 3},
            { 5, 0, 6, 7},
            { 8, 9,10,11},
            {12,13,14,15}
        };

        int expected[4][4] = {
            { 4, 1, 2, 3},
            { 0, 5, 6, 7},
            { 8, 9,10,11},
            {12,13,14,15}
        };

        Game15Field field;

        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                field.cells[i][j] = init[i][j];
            }
        }

        make_turn_game(&field, RIGHT);

        bool isPassed = true;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(field.cells[i][j] != expected[i][j])
                {
                    isPassed = false;
                }
            }
        }

        EXPECT_EQ(true, isPassed);
    }

    TEST(MoveTest, MoveRightDeclined)
    {
        int init[4][4] = {
            { 4, 1, 2, 3},
            { 0, 5, 6, 7},
            { 8, 9,10,11},
            {12,13,14,15}
        };

        int expected[4][4] = {
            { 4, 1, 2, 3},
            { 0, 5, 6, 7},
            { 8, 9,10,11},
            {12,13,14,15}
        };

        Game15Field field;

        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                field.cells[i][j] = init[i][j];
            }
        }

        make_turn_game(&field, RIGHT);

        bool isPassed = true;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(field.cells[i][j] != expected[i][j])
                {
                    isPassed = false;
                }
            }
        }

        EXPECT_EQ(true, isPassed);
    }


    TEST(EndTest, EndAccepted)
    {
        int init[4][4] = {
            { 1, 2, 3, 4},
            { 5, 6, 7, 8},
            { 9,10,11,12},
            {13,14,15, 0}
        };

        int expected = true;

        Game15Field field;

        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                field.cells[i][j] = init[i][j];
            }
        }

        int acually = is_end_game(field);

        EXPECT_EQ(expected, acually);
    }

    TEST(EndTest, EndDeclined)
    {
        int init[4][4] = {
            { 1, 2, 3, 4},
            { 5, 0, 7, 8},
            { 9,10,11,12},
            {13,14,15, 6}
        };

        int expected = 0;

        Game15Field field;

        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                field.cells[i][j] = init[i][j];
            }
        }

        int acually = is_end_game(field);

        EXPECT_EQ(expected, acually);
    }
}

