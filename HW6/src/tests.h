/*
 * tests.h
 *
 *  Created on: Oct 2, 2019
 *      Author: kushal
 */

#ifndef TESTS_H_
#define TESTS_H_


#include "production.h"
#include <stdbool.h>
#include <iostream>
using namespace std;

class tests {
public:
	tests();
	virtual ~tests();
	bool runTests();
	bool testPlaceShipOnBoard();

};




#endif /* TESTS_H_ */
