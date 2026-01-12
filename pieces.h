#include "internals.h"

struct PieceMetadata {
	char      color;
    char      name;
    Texture2D texture;
};

struct Piece {
    int            column;
    int            line;
    bool           moved;
    bool*          you;
    PieceMetadata* metadata;
};

enum { IDX_BLACK, IDX_WHITE };
enum { IDX_BISHOP, IDX_KING, IDX_KNIGHT, IDX_PAWN, IDX_QUEEN, IDX_ROOK };

extern PieceMetadata* piecesMetadata[2][6];

char getColorPiece(bool is_you);

// 0 = 'a' and 7 = 'h'
char convertColumnIntPosToChar(int pos);

// 0 = '1' and 7 = '8'
char convertLineIntPosToChar(int pos);

void nameVerificationMsg();

bool nameVerification(char name);

bool colorVerification(char color);

void allocPieceMetadata(PieceMetadata** metadata, char color, char name, const char* texture_path);

PieceMetadata* pieceMetadaDispatch(char color, char name);

Piece* createPiece(char color, char name, int column, int line);

void startPawns();

void startPiecesFromLine(int line);

void startPieces();