/*
 * tests.h
 *
 *  Created on: Oct 2, 2019
 *      Author: kushal
 */

#ifndef TESTS_H_
#define TESTS_H_


#include <stdbool.h>
#include <iostream>

#include "interaction.h"
using namespace std;

class tests {
public:
	tests();
	virtual ~tests();
	bool runTests();
	bool testPutShipOnGameBoard();
	bool testManuallyPlaceShipOnBoard();
	bool testCheckSunkShip();
	bool testisValidLocation();
	bool testIsWinner();
	bool testCHeckShot();

};




#endif /* TESTS_H_ */
