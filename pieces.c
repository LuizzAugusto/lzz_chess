#ifndef __CHESS_G_PIECES__
#define __CHESS_G_PIECES__

#include "internals.h"

PieceMetadata* piecesMetadata[2][6];

char getColorPiece(bool is_white) {
    if (is_white) {
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

void nameVerificationMsg() {
    printf("alloc error, trying allocate an unexistent piece, use 'K' for King, 'Q' for Queen, 'R' for Rook, 'N' for Knight, 'B' for Bishop and 'P' for Pawn.\n");
}

bool colorAssert(char color) {
    bool assert = color == 'b' || color == 'w';
    
    if (!assert) {
        printf("alloc error, trying allocate an unexistent color, use 'b' for black and 'w' for white.\n");
    }

    return assert;
}

void allocPieceMetadata(PieceMetadata** metadata, char color, char name, const char* texture_path) {
    *metadata = malloc(sizeof(PieceMetadata));
    (*metadata)->color = color;
    (*metadata)->name = name;
    (*metadata)->texture = LoadTexture(texture_path);
}

PieceMetadata* pieceMetadaDispatch(char color, char name) {
    if (!colorAssert(color)) {
        return NULL;
    }

    int color_index;
    int name_index;

    color_index = color == 'b' ? IDX_BLACK : IDX_WHITE;

    switch (name) {
        case 'B': name_index = IDX_BISHOP; break;
        case 'K': name_index = IDX_KING;   break;
        case 'N': name_index = IDX_KNIGHT; break;
        case 'P': name_index = IDX_PAWN;   break;
        case 'Q': name_index = IDX_QUEEN;  break;
        case 'R': name_index = IDX_ROOK;   break;
        default:
            nameVerificationMsg();
            return NULL;
    }

    PieceMetadata* metadata = piecesMetadata[color_index][name_index];

    if (metadata == NULL) {
        char texture_path[24];
        sprintf(texture_path, "assets/pixel/png/%c%c.png", color, name);
        allocPieceMetadata(&metadata, color, name, texture_path);
    }

    return metadata;
}

Piece* createPiece(char color, char name, int column, int line) {
    if (column < 0 || column > 7) {
        printf("alloc error, invalid column space, use 'a' to 'h' only.\n");
        return NULL;
    }

    if (line < 0 || line > 7) {
        printf("alloc error, invalid line space, use '1' to '8' only.\n");
        return NULL;
    }
    
    PieceMetadata* metadata = pieceMetadaDispatch(color, name);

    if (!metadata) {
        printf("can't load metadata.\n");
        return NULL;
    }

    Piece* piece = malloc(sizeof(Piece));
    piece->metadata = metadata;
    piece->column = column;
    piece->line = line;
    piece->moved = false;
    piece->you = you_start;

    return piece;
}

void startPawns() {
    for (int column = 0; column < 8; column++) {
        board[column][1] = createPiece(getColorPiece(!*you_start),	'P', column, 1);
        board[column][6] = createPiece(getColorPiece(*you_start),	'P', column, 6);
    }
}

// line 0 or 7
void startPiecesFromLine(int line) {
    bool is_white = *you_start ^ line == 0;

    board[0][line] = createPiece(getColorPiece(is_white), 'R', 0, line);
    board[1][line] = createPiece(getColorPiece(is_white), 'N', 1, line);
    board[2][line] = createPiece(getColorPiece(is_white), 'B', 2, line);

    if (!*you_start) {
        board[3][line] = createPiece(getColorPiece(is_white), 'K', 3, line);
        board[4][line] = createPiece(getColorPiece(is_white), 'Q', 4, line);
    } else {
        board[3][line] = createPiece(getColorPiece(is_white), 'Q', 3, line);
        board[4][line] = createPiece(getColorPiece(is_white), 'K', 4, line);
    }

    board[5][line] = createPiece(getColorPiece(is_white), 'B', 5, line);
    board[6][line] = createPiece(getColorPiece(is_white), 'N', 6, line);
    board[7][line] = createPiece(getColorPiece(is_white), 'R', 7, line);
}

void startPieces() {
    startPiecesFromLine(0);
    startPawns();
    startPiecesFromLine(7);
}

#endif