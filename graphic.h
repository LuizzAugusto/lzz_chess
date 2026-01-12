#include "internals.h"

extern Color CLR_LIGHT_SQUARE;
extern Color CLR_DARK_SQUARE;

void showTable(int square_area, Color color);

void drawPiece(Piece* piece, int square_area);

void showPieces(Piece* board[8][8], int square_area);