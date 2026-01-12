#ifndef __CHESS_G_INTERNALS__
#define __CHESS_G_INTERNALS__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#include "raylib.h"

typedef struct PieceMetadata PieceMetadata;
typedef struct Piece         Piece;

extern PieceMetadata* piecesMetadata[2][6];
extern Piece* board[8][8];

#include "pieces.h"
#include "board.h"
#include "graphic.h"

#endif