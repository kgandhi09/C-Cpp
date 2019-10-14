/*
 * tests.h
 *
 *  Created on: Sep 10, 2019
 *      Author: kushal
 */

#ifndef TESTS_H_
#define TESTS_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool tests(void);
bool testReadFileIntoHouse(int** houseArr);
bool testReadFileIntoTreasure(int* treasureArr);
bool testAdjRooms(int** houseArr);
bool testAmtTreasure(int* treasureArr);

#endif /* TESTS_H_ */
