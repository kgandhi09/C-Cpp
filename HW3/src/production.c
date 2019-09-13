/*
 * production.c
 *
 *  Created on: Sep 11, 2019
 *      Author: kushal
 */
#include "production.h"
#include "Layout.h"
#include "Search.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>



bool production(int argc, char** argv)
{
	bool answer = true;
	char* ePtr=(char*)malloc(sizeof(char*));

	int nRooms=strtol(argv[1],&ePtr,10); // command line argument 1
	int limTreasure=strtol(argv[2],&ePtr,10); // command line argument 2

	treasureLimit=(int)limTreasure;
	nRows=(int)nRooms;
	nCols=(int)nRooms;
	
	int nRoomsFromSearch = getNumRooms();

	printf("%s%d%2d\n", "The command line arguments are - ", nRoomsFromSearch, limTreasure);
	
	//int** testArr = houseLayout(nRows,nCols);
	//printf("%d", testArr[0][0]);

	return answer;
}

