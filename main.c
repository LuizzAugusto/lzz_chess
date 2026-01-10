#include "pieces.c"
#include "graphic.c"

// typedef struct Historic Historic;

// struct Historic {
//     Historic *previous;
//     char *piece_prev_state;
//     char  *piece_new_state; 
// };

int main() {
    // Uses 'Pcl' pattern of chess, I add color ('b' and 'w') and moved ('0' or '1') too.
    char* table[8][8];
    int ustart = youStart(-1);
    int square_area = 80;
    Color colorBg = LIGHTGRAY;
    Color colorSquare = BROWN;
    // PiecesTexture piecesTexture;

    for (int line = 2; line < 6; line++) {
        for (int col = 0; col < 8; col++) {
            table[col][line] = '\0';
        }
    }

    char adversaryColor = ustart ? 'b' : 'w';
    char myColor = ustart ? 'w' : 'b';

    printf("-----------------------------------------\n");
    printf("ustart: %d\n", ustart);
    printf("-----------------------------------------\n");
    startPieces(table, adversaryColor, 0, ustart);
    startPieces(table, myColor, 7, ustart);
    
    InitWindow(square_area * 8, square_area * 8, "Chess");

    globalPiecesTexture.blackBishop	= LoadTexture("assets/pixel/png/bB.png");
    globalPiecesTexture.blackKing	= LoadTexture("assets/pixel/png/bK.png");
    globalPiecesTexture.blackKnight	= LoadTexture("assets/pixel/png/bN.png");
    globalPiecesTexture.blackPawn	= LoadTexture("assets/pixel/png/bP.png");
    globalPiecesTexture.blackQueen	= LoadTexture("assets/pixel/png/bQ.png");
    globalPiecesTexture.blackRook	= LoadTexture("assets/pixel/png/bR.png");

    globalPiecesTexture.whiteBishop	= LoadTexture("assets/pixel/png/wB.png");
    globalPiecesTexture.whiteKing	= LoadTexture("assets/pixel/png/wK.png");
    globalPiecesTexture.whiteKnight	= LoadTexture("assets/pixel/png/wN.png");
    globalPiecesTexture.whitePawn	= LoadTexture("assets/pixel/png/wP.png");
    globalPiecesTexture.whiteQueen	= LoadTexture("assets/pixel/png/wQ.png");
    globalPiecesTexture.whiteRook	= LoadTexture("assets/pixel/png/wR.png");

    while (!WindowShouldClose())
    {
        BeginDrawing();
		ClearBackground(colorBg);

        showTable(square_area, colorSquare);
        showPieces(table, square_area);

        EndDrawing();
    }

    CloseWindow();
}
