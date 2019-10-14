/*
 * king.h
 *
 *  Created on: Oct 4, 2019
 *      Author: kushal
 */

#ifndef KING_H_
#define KING_H_

#include <iostream>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <fstream>

class king{
public:
	#define nROWS 8
	#define nCOLS 8
	king();
	virtual ~king();
	void move(int d[][nCOLS], int x1, int x2, int y1, int y2, int player);
	int** possibleMoves(int d[][nCOLS], int x, int y, int player);
	int** findPossiblePiecesToMove(int d[][nCOLS], int player);

};




#endif /* KING_H_ */
