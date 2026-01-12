#ifndef __CHESS_G_PIECES__
#define __CHESS_G_PIECES__

#include "internals.h"

// black pieces
PieceMdt* bBishopMd = NULL;
PieceMdt* bKingMd = NULL;
PieceMdt* bKnightMd = NULL;
PieceMdt* bPawnMd = NULL;
PieceMdt* bQueenMd = NULL;
PieceMdt* bRookMd = NULL;
// white pieces
PieceMdt* wBishopMd = NULL;
PieceMdt* wKingMd = NULL;
PieceMdt* wKnightMd = NULL;
PieceMdt* wPawnMd = NULL;
PieceMdt* wQueenMd = NULL;
PieceMdt* wRookMd = NULL;

int youStart(int confirm) {
    if (confirm < 0) {
        srandom(time(NULL));
        return rand() % 2;
    }

    return confirm;
}

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

void allocPieceMetadata(PieceMdt** metadata, char color, char name, const char* texture_path) {
    *metadata = malloc(sizeof(PieceMdt));
    (*metadata)->color = color;
    (*metadata)->name = name;
    (*metadata)->texture = LoadTexture(texture_path);
}

PieceMdt* pieceMetadaDispatch(char color, char name) {
    if (!colorAssert(color)) {
        return NULL;
    }

    PieceMdt* metadata;

    if (color == 'b') {
        switch (name) {
            case 'B':
                metadata = bBishopMd;
                break;
            case 'K':
                metadata = bKingMd;
                break;
            case 'N':
                metadata = bKnightMd;
                break;
            case 'P':
                metadata = bPawnMd;
                break;
            case 'Q':
                metadata = bQueenMd;
                break;
            case 'R':
                metadata = bRookMd;
                break;
            default:
                metadata = NULL;
                nameVerificationMsg();
                break;
        }
    } else {
        switch (name) {
            case 'B':
                metadata = wBishopMd;
                break;
            case 'K':
                metadata = wKingMd;
                break;
            case 'N':
                metadata = wKnightMd;
                break;
            case 'P':
                metadata = wPawnMd;
                break;
            case 'Q':
                metadata = wQueenMd;
                break;
            case 'R':
                metadata = wRookMd;
                break;
            default:
                metadata = NULL;
                nameVerificationMsg();
                break;
        }
    }

    return metadata;
}

Piece* createPiece(char color, char name, int column, int line, bool is_you) {
    if (column < 0 || column > 7) {
        printf("alloc error, invalid column space, use 'a' to 'h' only.\n");
        return NULL;
    }

    if (line < 0 || line > 7) {
        printf("alloc error, invalid line space, use '1' to '8' only.\n");
        return NULL;
    }
    
    PieceMdt* metadata = pieceMetadaDispatch(color, name);

    if (!metadata) {
        printf("can't load metadata.\n");
        return NULL;
    }

    Piece* piece = malloc(sizeof(piece));
    piece->metadata = metadata;
    piece->column = column;
    piece->line = line;
    piece->moved = false;
    piece->you = is_you;

    return piece;
}

void startPawns(Piece* board[8][8], bool is_you) {
    for (int column = 0; column < 8; column++) {
        board[column][1] = createPiece(getColorPiece(!is_you),	'P', column, 1, !is_you);
        board[column][6] = createPiece(getColorPiece(is_you),	'P', column, 6, is_you);
    }
}

// line 0 or 7
void startPiecesFromLine(Piece* board[8][8], int line, int ustart) {
    bool is_white = ustart && line == 7 || !ustart && line == 0;

    board[0][line] = createPiece(getColorPiece(is_white), 'R', 0, line, is_white);
    board[1][line] = createPiece(getColorPiece(is_white), 'N', 1, line, is_white);
    board[2][line] = createPiece(getColorPiece(is_white), 'B', 2, line, is_white);

    if (!ustart) {
        board[3][line] = createPiece(getColorPiece(is_white), 'K', 3, line, is_white);
        board[4][line] = createPiece(getColorPiece(is_white), 'Q', 4, line, is_white);
    } else {
        board[3][line] = createPiece(getColorPiece(is_white), 'Q', 3, line, is_white);
        board[4][line] = createPiece(getColorPiece(is_white), 'K', 4, line, is_white);
    }

    board[5][line] = createPiece(getColorPiece(is_white), 'B', 5, line, is_white);
    board[6][line] = createPiece(getColorPiece(is_white), 'N', 6, line, is_white);
    board[7][line] = createPiece(getColorPiece(is_white), 'R', 7, line, is_white);
}

void startPieces(Piece* board[8][8], int ustart) {
    startPiecesFromLine(board, 0, ustart);
    startPawns(board, ustart);
    startPiecesFromLine(board, 7, ustart);
}

#endif