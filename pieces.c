#include "internals.c"

// For explanation: it didn't use structs, because I want to save historic
// in chess-like style and struct will lead for more convertions.
char *allocPiece(char color, char name, char col, char line, char moved) {
    if (color != 'b' && color != 'w') {
        printf("alloc error, trying allocate an unexistent color, use 'b' for black and 'w' for white.\n");
        return NULL;
    }

    if (name != 'K' && name != 'Q' && name != 'R' && name != 'N' && name != 'B' && name != 'P') {
        printf("alloc error, trying allocate an unexistent piece, use 'K' for King, 'Q' for Queen, 'R' for Rook, 'N' for Knight, 'B' for Bishop and 'P' for Pawn.\n");
        return NULL;
    }

    if (col < 'a' || col > 'h') {
        printf("alloc error, invalid column space, use 'a' to 'h' only.\n");
        return NULL;
    }

    if (line < '1' || line > '8') {
        printf("alloc error, invalid line space, use '1' to '8' only.\n");
        return NULL;
    }

    if (moved != '0' && moved != '1') {
        printf("alloc error, use '1' for moved, or '0' for unmoved.\n");
        return NULL;
    }

    char *piece = malloc(6);

    piece[IDX_COLOR] = color;
    piece[IDX_PIECE_NAME] = name;
    piece[IDX_COLUMN] = col;
    piece[IDX_LINE] = line;
    piece[IDX_MOVED] = moved;
    piece[5] = '\0';

    return piece;
}

int youStart(int confirm) {
    if (confirm < 0) {
        srandom(time(NULL));
        return rand() % 2;
    }

    return confirm;
}

char blackOrWhite(int ustart) {
    if (ustart) {
        return 'w';
    }

    return 'b';
}

// 0 = 'a' and 7 = 'h'
char convertColumnIntPosToChar(int pos) {
    return pos + 97;
}

// 0 = '1' and 7 = '8'
char convertLineIntPosToChar(int pos) {
    return pos + 49;
}

void startPawns(char *table[8][8], int ustart) {
    for (int column = 0; column < 8; column++) {
        table[column][1] = allocPiece(blackOrWhite(!ustart), 'P', convertColumnIntPosToChar(column), convertLineIntPosToChar(1), '0');
        table[column][6] = allocPiece(blackOrWhite(ustart), 'P', convertColumnIntPosToChar(column), convertLineIntPosToChar(6), '0');
    }
}

void startPieces(char *table[8][8], char color, int line, int ustart) {
    startPawns(table, ustart);

    table[0][line] = allocPiece(color, 'R', convertColumnIntPosToChar(0), convertLineIntPosToChar(line), '0');
    table[1][line] = allocPiece(color, 'N', convertColumnIntPosToChar(1), convertLineIntPosToChar(line), '0');
    table[2][line] = allocPiece(color, 'B', convertColumnIntPosToChar(2), convertLineIntPosToChar(line), '0');

    if (!ustart) {
        table[3][line] = allocPiece(color, 'K', convertColumnIntPosToChar(3), convertLineIntPosToChar(line), '0');
        table[4][line] = allocPiece(color, 'Q', convertColumnIntPosToChar(4), convertLineIntPosToChar(line), '0');
    } else {
        table[3][line] = allocPiece(color, 'Q', convertColumnIntPosToChar(3), convertLineIntPosToChar(line), '0');
        table[4][line] = allocPiece(color, 'K', convertColumnIntPosToChar(4), convertLineIntPosToChar(line), '0');
    }

    table[5][line] = allocPiece(color, 'B', convertColumnIntPosToChar(5), convertLineIntPosToChar(line), '0');
    table[6][line] = allocPiece(color, 'N', convertColumnIntPosToChar(6), convertLineIntPosToChar(line), '0');
    table[7][line] = allocPiece(color, 'R', convertColumnIntPosToChar(7), convertLineIntPosToChar(line), '0');
}