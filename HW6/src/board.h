/*
 * board.h
 *
 *  Created on: Oct 9, 2019
 *      Author: kushal
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <fstream>
using namespace std;

#define ROWS 10
#define COLS 10
#define WATER         '~'
#define HIT           '*'
#define MISS          'm'


#define CARRIER       'c'
#define BATTLESHIP    'b'
#define CRUISER       'r'
#define SUBMARINE     's'
#define DESTROYER     'd'

typedef enum {
	FALSE, TRUE
} Boolean;

typedef struct coordinate {
	int        row;
	int        column;
} Coordinate;

typedef struct cell {
	char       symbol;
	Coordinate position;
} Cell;

class board{
public:


	board();
	virtual ~board();



	void initializeGameBoard (Cell gameBoard[][COLS]);
	void printGameBoard (Cell gameBoard [][COLS], Boolean showPegs);
	void updateGameBoard (Cell gameBoard[][COLS], Coordinate target);

};




#endif /* BOARD_H_ */
