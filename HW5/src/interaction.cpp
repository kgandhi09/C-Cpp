/*
 * interaction.cpp
 *
 *  Created on: Oct 3, 2019
 *      Author: kushal
 */

#include "interaction.h"

interaction::interaction() {

}

interaction::~interaction() {

}

void interaction::runInteraction() {

	int d[nROWS][nCOLS] = { { 0, 1, 0, 1, 0, 1, 0, 1 },
			{ 1, 0, 1, 0, 1, 0, 1, 0 }, { 0, 1, 0, 1, 0, 1, 0, 1 }, { 0, 0, 0,
					0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0, 0 }, { 2, 0, 2, 0,
					2, 0, 2, 0 }, { 0, 2, 0, 2, 0, 2, 0, 2 }, { 2, 0, 2, 0, 2,
					0, 2, 0 } };
	pawn p = pawn();
	printBoard(d);
	printf("\n\n");
	int** possiblePiecesToMove = p.findPossiblePiecesToMove(d, 2);
	printf("Possible pieces that can be moved are - \n");
	printLocationArray(4, possiblePiecesToMove);
	p.move(d,possiblePiecesToMove,2);
}

void interaction::printBoard(int d[][nCOLS]) {

	printf("  +---+---+---+---+---+---+---+---+\n");

	for (int r = 0; r < nROWS; r++) {
		printf("%d |", r + 1);
		for (int c = 0; c < nCOLS; c++) {
			printf(" %c |", value2symbol(d[r][c]));
		}
		printf("\n");
		printf("  +---+---+---+---+---+---+---+---+\n");
	}

	printf("    A   B   c   D   E   F   G   H\n");

}

char interaction::value2symbol(int i) {
	switch (i) {
	case 0:
		return ' ';
	case 1:
		return 'R';
	case 2:
		return 'B';
	}
	return ('?');
}

void interaction::print2DArray(int rows, int cols, int** arr) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%2d", arr[i][j]);
		}
		printf("\n");
	}
}

void interaction::printLocationArray(int rows, int** arr) {
	for (int i = 0; i < rows; i++) {
		printf("%c%d\n", char('A' + arr[i][0]), arr[i][1]);
	}
	printf("\n");
}

void interaction::print1DArray(int rows, int* arr) {
	for (int i = 0; i < rows; i++) {
		printf("%3d", arr[i]);
	}
	printf("\n");
}

