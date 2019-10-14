/*
 * tests.c
 *
 *  Created on: Sep 10, 2019
 *      Author: kushal
 */

#include "tests.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "House.h"


int nRooms;
nRooms = 7;

bool tests(void)
{
	bool results=false;

		int** houseArr = readFileIntoHouse(nRooms, fp);
		int* treasureArr = readFileIntoTreasure(nRooms, fp);

		printf("These are tests !\n"); fflush(stdout);

		bool ok1 = testReadFileIntoHouse(houseArr);
		printf("This test reads house layout from file\n"); fflush(stdout);

		bool ok2 = testReadFileIntoTreasure(treasureArr);
		printf("This test reads treasures from file\n"); fflush(stdout);

		bool ok3 = testAdjRooms(houseArr);
		printf("This test finds adjacent rooms to the given room\n"); fflush(stdout);

		bool ok4 = testAmtTreasure(treasureArr);
		printf("This test finds the amount of treasure present in that particular room\n"); fflush(stdout);

		results = ok1 && ok2 && ok3 && ok4;
	return results;
}

bool testReadFileIntoHouse(int** houseArr)
{

	bool ok = true;
	print2DArray(nRooms, nRooms, houseArr);
	return ok;
}

bool testReadFileIntoTreasure(int* treasureArr){

	bool ok = true;
	print1DArray(nRooms, treasureArr);

	return ok;

}

bool testAdjRooms(int** houseArr){
	bool ok = true;
	int* adjRooms = adjacentRooms(houseArr, 1, nRooms);
	print1DArray(nRooms, adjRooms);
	return ok;
}

bool testAmtTreasure(int* treasureArr){
	bool ok = false;
	int treasureRoom1 = amtTreasure(1, treasureArr, nRooms);
	if (treasureRoom1 == treasureArr[0]){
		ok = true;
	}
	return ok;
}


