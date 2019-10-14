/*
 * board.cpp
 *
 *  Created on: Oct 9, 2019
 *      Author: kushal
 */

#include "board.h"
using namespace std;

board::board(){

}

board::~board(){

}

void board::initializeGameBoard (Cell gameBoard[][COLS]) {
	int i = 0, j = 0;

	for (i = 0; i < ROWS; i++)
		for (j = 0; j < COLS; j++) {
			gameBoard[i][j].symbol          = WATER;
			gameBoard[i][j].position.row    = i;
			gameBoard[i][j].position.column = j;
		}
}

void board::printGameBoard (Cell gameBoard [][COLS], Boolean showPegs) {
	int i = 0, j = 0;

	cout  << "  0 1 2 3 4 5 6 7 8 9\n";
	for (i = 0; i < ROWS; i++) {
		printf ("%d ", i);

		for (j = 0; j < COLS; j++) {
			if (showPegs == TRUE)
				printf ("%c ", gameBoard [i][j].symbol);
			else {
				switch (gameBoard [i][j].symbol) {
					case HIT:   printf ("%c ", HIT);   break;
					case MISS:  printf ("%c ", MISS);  break;
					case WATER:
					default:    printf ("%c ", WATER); break;
				}
			}
		}

		putchar ('\n');
	}
}

void board::updateGameBoard (Cell gameBoard[][COLS], Coordinate target) {
	switch (gameBoard[target.row][target.column].symbol) {
		/* miss */
		case WATER:
			gameBoard[target.row][target.column].symbol = MISS;
			break;

		/* hit */
		case CARRIER:
		case BATTLESHIP:
		case CRUISER:
		case SUBMARINE:
		case DESTROYER:
			gameBoard[target.row][target.column].symbol = HIT;
			break;

		case HIT:
		case MISS:
		default:
			break;
	}
}

