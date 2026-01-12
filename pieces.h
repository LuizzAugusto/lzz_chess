#include "internals.h"

typedef struct PieceMdt	PieceMdt;
typedef struct Piece	Piece;

struct PieceMdt {
	char		color;
    char		name;
    Texture2D	texture;
};

struct Piece {
    int			column;
    int			line;
    bool		moved;
    bool		you;
    PieceMdt*	metadata;
};

enum { IDX_BLACK, IDX_WHITE };
enum { IDX_BISHOP, IDX_KING, IDX_KNIGHT, IDX_PAWN, IDX_QUEEN, IDX_ROOK };

extern PieceMdt* piecesMetadata[2][6];

int youStart(int confirm);

char getColorPiece(bool is_you);

// 0 = 'a' and 7 = 'h'
char convertColumnIntPosToChar(int pos);

// 0 = '1' and 7 = '8'
char convertLineIntPosToChar(int pos);

void nameVerificationMsg();

bool nameVerification(char name);

bool colorVerification(char color);

void allocPieceMetadata(PieceMdt** metadata, char color, char name, const char* texture_path);

PieceMdt* pieceMetadaDispatch(char color, char name);

Piece* createPiece(char color, char name, int column, int line, bool is_you);

void startPawns(Piece* board[8][8], bool is_you);

void startPiecesFromLine(Piece* board[8][8], int line, int ustart);

void startPieces(Piece* board[8][8], int ustart);