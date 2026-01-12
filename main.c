#include "internals.h"

#include "board.c"
#include "pieces.c"
#include "graphic.c"

// typedef struct Historic Historic;

// struct Historic {
//     Historic *previous;
//     char *piece_prev_state;
//     char  *piece_new_state; 
// };

int main() {
    int square_area = 80;

    you_start = malloc(sizeof(bool));
    *you_start = youStart(-1);
    memset(board, 0, sizeof(board));
    memset(piecesMetadata, 0, sizeof(piecesMetadata));

    const char* you_start_msg = you_start ? "you start" : "adversary start";

    printf("-----------------------------------------\n");
    printf("%s\n", you_start_msg);
    printf("-----------------------------------------\n");

    InitWindow(square_area * 8, square_area * 8, "Chess");

    startPieces(you_start);

    while (!WindowShouldClose())
    {
        BeginDrawing();
		    ClearBackground(CLR_LIGHT_SQUARE);
            showTable(square_area, CLR_DARK_SQUARE);
            showPieces(square_area);
        EndDrawing();
    }

    CloseWindow();
}
