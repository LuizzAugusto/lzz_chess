#ifndef __CHESS_G_BOARD__
#define __CHESS_G_BOARD__

#include "internals.h"

Piece* board[8][8];
bool* you_start;

bool youStart(int confirm) {
    if (confirm < 0) {
        srandom(time(NULL));
        return rand() % 2;
    }

    return confirm;
}

#endif