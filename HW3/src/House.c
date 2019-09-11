/*
 * production.c
 *
 *  Created on: Sep 10, 2019
 *      Author: kushal
 */

#include "House.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

int nRows=0;
int nCols=0;
int treasureLimit=0;


bool production(int argc, char* argv[])
{
	bool answer = true;
	char* ePtr=(char*)malloc(sizeof(char*));
	
	int nRooms=strtol(argv[1],&ePtr,10); // command line argument 1
	int limTreasure=strtol(argv[2],&ePtr,10); // command line argument 2

	treasureLimit=(int)limTreasure;	
	nRows=(int)nRooms;
	nCols=(int)nRooms;

	printf("%s%d%2d\n", "The command line arguments are - ", nRooms, limTreasure);

	//int** testArr = houseLayout(nRows,nCols);
	//printf("%d", testArr[0][0]);
	
	return answer;
}

/*

int** houseLayout(int rows, int cols){
	int** theArray = (int**)malloc(sizeof(int)*rows*cols);
	for(int i = 0; i<rows; i++){
		for(int j = 0; j<cols; j++){
			theArray[i][j] = 0;	
		}
	}

	return theArray;
}
*/
