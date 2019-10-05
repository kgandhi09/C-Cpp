/*
 * pawn.h
 *
 *  Created on: Oct 4, 2019
 *      Author: kushal
 */

#ifndef PAWN_H_
#define PAWN_H_

#include <iostream>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <fstream>


class pawn{
public:
	#define nROWS 8
	#define nCOLS 8
	pawn();
	virtual ~pawn();
	void move(int d[][nCOLS], int** arr, int player);
	int** possibleMoves(int d[][nCOLS], int x, int y, int player);
	int** findPossiblePiecesToMove(int d[][nCOLS], int player);
	void print2DArray(int rows, int cols, int** arr);
	void print1DArray(int rows, int* arr);
	void printLocationArray(int rows, int** arr);
};



#endif /* PAWN_H_ */
