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

    memset(board, 0, sizeof(board));
    memset(piecesMetadata, 0, sizeof(piecesMetadata));

    const char* you_start_msg = ustart ? "you start" : "adversary start";

    printf("-----------------------------------------\n");
    printf("%s\n", you_start_msg);
    printf("-----------------------------------------\n");

    InitWindow(square_area * 8, square_area * 8, "Chess");

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
