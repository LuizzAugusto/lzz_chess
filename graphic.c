#ifndef __CHESS_G_GRAPHIC__
#define __CHESS_G_GRAPHIC__

#include "internals.h"

Color CLR_LIGHT_SQUARE = LIGHTGRAY;
Color CLR_DARK_SQUARE = BROWN;

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

void drawPiece(Piece* piece, int square_area) {
	double spacing = 0.05;

	DrawTexture(
		piece->metadata->texture,
		piece->column	* square_area + square_area * spacing,
		piece->line		* square_area + square_area * spacing,
		LIGHTGRAY
	);
}

void showPieces(Piece* board[8][8], int square_area) {
	for (int col = 0; col < 8; col++) {
		for (int line = 0; line < 8; line++) {
			Piece* piece = board[col][line];

			if (piece)
				drawPiece(piece, square_area);
		}
	}
}

#endif