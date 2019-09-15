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
	
	//char *filename = (char)malloc(sizeof(char)*)
	char filename[100];
	for(int i =0; i<100; i++){
		filename[i] = '\0';
	}
	char print = 'n';
	char pasue = 'n';
	
	strcpy(filename, argv[1]);

	int maxRoomsToSearch =strtol(argv[2],&ePtr,10); // command line argument 1 - max no of rooms to search in house
	int limTreasure=strtol(argv[3],&ePtr,10); // command line argument 2 - total limit of treasure found
	puts("Im here!");
	int treasureLimit=(int)limTreasure;
	//nRows=(int)nRooms;
	//nCols=(int)nRooms;

	FILE* fp = fopen(filename, "r");
	int arr[43];	
	for(int i =0; i<43; i++){ // initialize the array with null chars
		//for(int j = 0; j < 7; j++){
			arr[i]=0;
		//}
	}
	for(int i =0; i<43; i++){
		//fscanf(fp, "%hhd", &arr[i][j]);
		//for(){		
		fscanf(fp,"%d", &arr[i]);
		//}
	}

	for(int l =0; l<43; l++){
		//for(int m = 0; m < 7; m++){
		printf("%d", arr[l]);
		//}
		printf("\n");
	}
		

	int nRooms = getNumRooms();

	//printf("%s%s%2d%2d\n", "The command line arguments are - ", filename, maxRoomsToSearch, limTreasure);
	
	//int** testArr = houseLayout(nRows,nCols);
	//printf("%d", testArr[0][0]);

	return answer;
}



