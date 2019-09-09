/*
 * tests.c
 *
 *  Created on: Sep 6, 2019
 *      Author: kushal
 */


#include "tests.h"
#include <stdbool.h>
#include "production.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 




bool tests(void)
{
	bool results=false;
	puts("During tests\n");

	bool ok1 = testPrintArray();
	if(ok1)puts("Prints the Array!\n");

	bool ok2 = testGetMarkerPos();
	if(ok2)puts("prints the pos of test array!\n");

	bool ok3 = testPlaceMarker();
	if(ok3)puts("places the marker and prints it!\n");
	
	bool ok4 = testMoveMarker();
	if(ok4)puts("moves the position of marker from (1,1) to random position and prints it!\n");
	
	results = ok1 && ok2 && ok3 && ok4;
	printf("tests returning %d.\n",results);
	return results;
}

bool testMoveMarker(){
	int** testArr = make2Darray(3,3);
	placeMarker(1, 1, 1, testArr);
	moveMarker(testArr, 3,3);
	//printArray(3,3,testArr);
	return true;
}

bool testPlaceMarker(){
	int** testArr = make2Darray(3,3);
	placeMarker(1, 1, 1, testArr);
	printArray(3,3, testArr);
	return true;
}

bool testGetMarkerPos(){
	int** testArr = make2Darray(3,3);
	//printArray(3,3,testArr);
	testArr[1][2] = 1;
	int* markerPos = getMarkerPos(testArr,3,3);
	int row = markerPos[0];
	int col = markerPos[1];
	printf("%d,%d\n", row, col);
	return true;
}


bool testPrintArray(){
	int** testArr = make2Darray(3,3);
	printArray(3,3, testArr);
	return true;

}
