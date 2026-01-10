#include "internals.c"

#include "raylib.h"

typedef struct PiecesTexture PiecesTexture;

struct PiecesTexture {
	Texture2D blackBishop;
	Texture2D blackKing;
	Texture2D blackKnight;
	Texture2D blackPawn;
	Texture2D blackQueen;
	Texture2D blackRook;

	Texture2D whiteBishop;
	Texture2D whiteKing;
	Texture2D whiteKnight;
	Texture2D whitePawn;
	Texture2D whiteQueen;
	Texture2D whiteRook;
};

PiecesTexture globalPiecesTexture;

void showTable(int square_area, Color color) {
	for (int i = 0; i < 8; i += 2) {
		DrawRectangle(0 * square_area, i * square_area, square_area, square_area, color);
		DrawRectangle(1 * square_area, (i + 1) * square_area, square_area, square_area, color);

		DrawRectangle(2 * square_area, i * square_area, square_area, square_area, color);
		DrawRectangle(3 * square_area, (i + 1) * square_area, square_area, square_area, color);

		DrawRectangle(4 * square_area, i * square_area, square_area, square_area, color);
		DrawRectangle(5 * square_area, (i + 1) * square_area, square_area, square_area, color);

		DrawRectangle(6 * square_area, i * square_area, square_area, square_area, color);
		DrawRectangle(7 * square_area, (i + 1) * square_area, square_area, square_area, color);
	}
}

// Color drawColorPiece(char color) {
// 	if (color == 'b') {
// 		return DARKGRAY;
// 	}

// 	if (color == 'w') {
// 		return WHITE;
// 	}

// 	printf("graphic error, not a valid color piece.\n");
// 	return RED;
// }

Texture2D getPieceTexture(char piece_color, char piece_name) {
	Texture2D texture;

	if (piece_color == 'b') {
		switch (piece_name) {
			case 'B':
				texture = globalPiecesTexture.blackBishop;
				break;
			case 'K':
				texture = globalPiecesTexture.blackKing;
				break;
			case 'N':
				texture = globalPiecesTexture.blackKnight;
				break;
			case 'P':
				texture = globalPiecesTexture.blackPawn;
				break;
			case 'Q':
				texture = globalPiecesTexture.blackQueen;
				break;
			case 'R':
				texture = globalPiecesTexture.blackRook;
				break;
			default:
				break;
		}
	}
	else if (piece_color == 'w') {
		switch (piece_name) {
			case 'B':
				texture = globalPiecesTexture.whiteBishop;
				break;
			case 'K':
				texture = globalPiecesTexture.whiteKing;
				break;
			case 'N':
				texture = globalPiecesTexture.whiteKnight;
				break;
			case 'P':
				texture = globalPiecesTexture.whitePawn;
				break;
			case 'Q':
				texture = globalPiecesTexture.whiteQueen;
				break;
			case 'R':
				texture = globalPiecesTexture.whiteRook;
				break;
			default:
				break;
		}
	}

	return texture;
}

void drawPiece(char *piece, int line, int col, int square_area) {
	if (piece) {
		char piece_color = piece[IDX_COLOR];
		char piece_name = piece[IDX_PIECE_NAME];
		double spacing = 0.05;
		Texture2D texture = getPieceTexture(piece_color, piece_name);

		DrawTexture(texture, col * square_area + square_area * spacing, line * square_area + square_area * spacing, LIGHTGRAY);
	}
}

void showPieces(char *table[8][8], int square_area) {
	for (int col = 0; col < 8; col++) {
		for (int line = 0; line < 8; line++) {
			drawPiece(table[col][line], line, col, square_area);
		}
	}
}