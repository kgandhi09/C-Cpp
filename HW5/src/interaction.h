/*
 * interaction.h
 *
 *  Created on: Oct 3, 2019
 *      Author: kushal
 */

#ifndef INTERACTION_H_
#define INTERACTION_H_

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <fstream>

#include "pawn.h"

class interaction{
public:
	#define nROWS 8
	#define nCOLS 8
	interaction();
	virtual ~interaction();
	void runInteraction();
	char value2symbol(int i);
	void printBoard(int d[][nCOLS]);
	void print2DArray(int rows, int cols, int** arr);
	void print1DArray(int rows, int* arr);
	void printLocationArray(int rows, int** arr);

};



#endif /* INTERACTION_H_ */
