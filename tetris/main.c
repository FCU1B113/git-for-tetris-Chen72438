#include<stdio.h>

typedef enum {
    EMPTY = -1,
    I,
    J,
    L,
    O,
    S,
    T,
    Z
}ShapeId;

typedef enum
{
    RED = 41,
    GREEN,
    YELLOW,
    BLUE,
    PURPLE,
    CYAN,
    WHITE,
    BLACK = 0,
}Color;

typedef struct
{
    ShapeId shape;
    Color color;
    int size;
    char rotates[4][4][4];
}Shape;

Shape shape[7] = {
    {
        .shape = I,
        .color = CYAN,
        .size = 4,
        .rotates =
        {
            {
                {0,0,0,0},
                {1,1,1,1},
                {0,0,0,0},
                {0,0,0,0},
            },
            {
                {0,0,1,0},
                {0,0,1,0},
                {0,0,1,0},
                {0,0,1,0},
            },
            {
                {0,0,0,0},
                {0,0,0,0},
                {1,1,1,1},
                {0,0,0,0},
            },
            {
                {0,1,0,0},
                {0,1,0,0},
                {0,1,0,0},
                {0,1,0,0},
            }

        }
    },
    {
        .shape = J,
        .color = BLUE,
        .size = 3,
    },
    {
        .shape = L,
        .color = YELLOW,
        .size = 3,
    },
    {
        .shape = O,
        .color = WHITE,
        .size = 2,
        .rotates = {
            {
                {1,1},
                {1,1}
            },
            {
                {1,1},
                {1,1}
            },
            {
                {1,1},
                {1,1}
            },
            {
                {1,1},
                {1,1}
            }
        }
    },
    {
        .shape = S,
        .color = GREEN,
        .size = 3,
    },
    {
        .shape = T,
        .color = PURPLE,
        .size = 3,
    },
    {
        .shape = Z,
        .color = RED,
        .size = 3,
    },
};

int main() {
    Color clr;
    for (int i = 0; i < 7; i++) { //有7種方塊
        for (int j = 0; j < 4; j++) { //印出方塊樣式
            for (int s = 0; s < shape[i].size; s++) {
                for (int t = 0; t < shape[i].size; t++) {
                    if (shape[i].rotates[j][s][t] == 0) {
                        clr = WHITE;
                    }
                    else {
                        clr = shape[i].color;
                    }
                    printf("\033[%dm \033[0m", clr);
                }
                printf("\n");
            }
            printf("\n");
        }
    }
    return 0;
}