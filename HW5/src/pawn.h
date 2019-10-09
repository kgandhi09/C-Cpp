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
#include "king.h"

class pawn{
public:
	#define nROWS 8
	#define nCOLS 8
	pawn();
	virtual ~pawn();
	void move(int d[][nCOLS], int x1, int x2, int y1, int y2, int player);
	int** possibleMoves(int d[][nCOLS], int x, int y, int player);
	int** findPossiblePiecesToMove(int d[][nCOLS], int player);
	king makeKing(int d[][nCOLS], int x1,int  y1);
};



#endif /* PAWN_H_ */
