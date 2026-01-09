#include "internals.c"

// For explanation: it didn't use structs, because I want to save historic
// in chess-like style and struct will lead for more convertions.
char *allocPiece(char name, char col, char line, char color, char moved) {
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

    if (color != 'b' && color != 'w') {
        printf("alloc error, trying allocate an unexistent color, use 'b' for black and 'w' for white.\n");
        return NULL;
    }

    if (moved != '0' && moved != '1') {
        printf("alloc error, use '1' for moved, or '0' for unmoved.\n");
        return NULL;
    }

    char piece[6];

    piece[IDX_COLOR] = color;
    piece[IDX_PIECE_NAME] = name;
    piece[IDX_COLUMN] = col;
    piece[IDX_LINE] = line;
    piece[IDX_MOVED] = moved;
    piece[5] = '\0';

    char *dup = malloc(5);
    memcpy(dup, piece, 5);
    return dup;
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

void startPieces(char *table[8][8], int column, int ustart) {
    table[column][0] = allocPiece('R', convertColumnIntPosToChar(column), convertLineIntPosToChar(0), blackOrWhite(ustart), '0');
    table[column][1] = allocPiece('N', convertColumnIntPosToChar(column), convertLineIntPosToChar(1), blackOrWhite(ustart), '0');
    table[column][2] = allocPiece('B', convertColumnIntPosToChar(column), convertLineIntPosToChar(2), blackOrWhite(ustart), '0');

    if (ustart) {
        table[column][3] = allocPiece('Q', convertColumnIntPosToChar(column), convertLineIntPosToChar(3), blackOrWhite(ustart), '0');
        table[column][4] = allocPiece('K', convertColumnIntPosToChar(column), convertLineIntPosToChar(4), blackOrWhite(ustart), '0');
    }
    else {
        table[column][3] = allocPiece('K', convertColumnIntPosToChar(column), convertLineIntPosToChar(3), blackOrWhite(ustart), '0');
        table[column][4] = allocPiece('Q', convertColumnIntPosToChar(column), convertLineIntPosToChar(4), blackOrWhite(ustart), '0');
    }

    table[column][5] = allocPiece('B', convertColumnIntPosToChar(column), convertLineIntPosToChar(5), blackOrWhite(ustart), '0');
    table[column][6] = allocPiece('N', convertColumnIntPosToChar(column), convertLineIntPosToChar(6), blackOrWhite(ustart), '0');
    table[column][7] = allocPiece('R', convertColumnIntPosToChar(column), convertLineIntPosToChar(7), blackOrWhite(ustart), '0');
}

void startPawns(char *table[8][8], int ustart) {
    for (int line = 0; line < 8; line++) {
        table[0][line] = allocPiece('P', convertColumnIntPosToChar(0), convertLineIntPosToChar(line), blackOrWhite(!ustart), '0');
        table[7][line] = allocPiece('P', convertColumnIntPosToChar(7), convertLineIntPosToChar(line), blackOrWhite(ustart), '0');
    }
}