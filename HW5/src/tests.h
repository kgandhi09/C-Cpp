/*
 * tests.h
 *
 *  Created on: Oct 3, 2019
 *      Author: kushal
 */

#ifndef TESTS_H_
#define TESTS_H_

#include <iostream>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <fstream>
#include "pawn.h"
#include "interaction.h"

using namespace std;

class tests{
public:
#define nROWS 8
#define nCOLS 8
	tests();
	virtual ~tests();
	bool runTests();
	bool testFindPossiblePiecesToMove();
	bool testfindPossibleMoves();

};

#endif /* TESTS_H_ */
