#include "internals.h"

#include "pieces.c"
#include "graphic.c"

// typedef struct Historic Historic;

// struct Historic {
//     Historic *previous;
//     char *piece_prev_state;
//     char  *piece_new_state; 
// };

int main() {
    Piece* board[8][8];
    
    int ustart = youStart(-1);
    int square_area = 80;

    for (int column = 0; column < 8; column++) {
        for (int line = 0; line < 8; line++) {
            board[column][line] = NULL;
        }
    }

    const char* you_start_msg = ustart ? "you start" : "adversary start";

    printf("-----------------------------------------\n");
    printf("%s\n", you_start_msg);
    printf("-----------------------------------------\n");

    InitWindow(square_area * 8, square_area * 8, "Chess");

    // allocating all pieces metadata once.
    allocPieceMetadata(&bBishopMd,	'b', 'B', "assets/pixel/png/bB.png");
    allocPieceMetadata(&bKingMd,	'b', 'K', "assets/pixel/png/bK.png");
    allocPieceMetadata(&bKnightMd,	'b', 'N', "assets/pixel/png/bN.png");
    allocPieceMetadata(&bPawnMd,	'b', 'P', "assets/pixel/png/bP.png");
    allocPieceMetadata(&bQueenMd,	'b', 'Q', "assets/pixel/png/bQ.png");
    allocPieceMetadata(&bRookMd,	'b', 'R', "assets/pixel/png/bR.png");

    allocPieceMetadata(&wBishopMd,	'w', 'B', "assets/pixel/png/wB.png");
    allocPieceMetadata(&wKingMd,	'w', 'K', "assets/pixel/png/wK.png");
    allocPieceMetadata(&wKnightMd,	'w', 'N', "assets/pixel/png/wN.png");
    allocPieceMetadata(&wPawnMd,	'w', 'P', "assets/pixel/png/wP.png");
    allocPieceMetadata(&wQueenMd,	'w', 'Q', "assets/pixel/png/wQ.png");
    allocPieceMetadata(&wRookMd,	'w', 'R', "assets/pixel/png/wR.png");

    startPieces(board, ustart);

    while (!WindowShouldClose())
    {
        BeginDrawing();
		    ClearBackground(CLR_LIGHT_SQUARE);
            showTable(square_area, CLR_DARK_SQUARE);
            showPieces(board, square_area);
        EndDrawing();
    }

    CloseWindow();
}
