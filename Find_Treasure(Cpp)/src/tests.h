/*
 * tests.h
 *
 *  Created on: Sep 26, 2019
 *      Author: kushal
 */

#ifndef TESTS_H_
#define TESTS_H_

#include "production.h"
#include <stdbool.h>
#include <iostream>
#include <stdio.h>
using namespace std;

#include "production.h"
#include "controller.h"

class tests {
public:
	tests();
	virtual ~tests();
	bool runTests();
	bool testReadFileIntoHouse(int** houseArr);
	bool testReadFileIntoTreasure(int* treasureArr);
	bool testAdjRooms(int** houseArr);
	bool testAmtTreasure(int* treasureArr);

	int nRooms;


	FILE* fp = fopen("houseGraph.txt", "r");
	controller c = controller();

};



#endif /* TESTS_H_ */
