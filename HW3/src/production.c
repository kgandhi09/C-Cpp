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
	
	strcpy(filename, argv[1]);

	int maxRoomsToSearch =strtol(argv[2],&ePtr,10); // command line argument 1 - max no of rooms to search in house
	int limTreasure=strtol(argv[3],&ePtr,10); // command line argument 2 - total limit of treasure found
	
	int treasureLimit=(int)limTreasure;
	//nRows=(int)nRooms;
	//nCols=(int)nRooms;

	FILE* fp = fopen(filename, "r");
	
	//int** houseLayout=readFileIntoArray(6,6,43, fp);	
	
	//printArray(6,6,houseLayout);
	
	int nRooms = getNumRooms();

	//printf("%s%s%2d%2d\n", "The command line arguments are - ", filename, maxRoomsToSearch, limTreasure);
	
	//int** testArr = houseLayout(nRows,nCols);
	//printf("%d", testArr[0][0]);

	return answer;
}

int** readFileIntoArray(int rows, int cols, int nElements, FILE* fp){
	int* arr=(int*)malloc(nElements * sizeof(int));
	//int newArr[rows][cols];
	
	for(int i =0; i<nElements; i++){
			arr[i]=0;
	}
	
	for(int i =0; i<nElements; i++){		
		fscanf(fp,"%d", &arr[i]);
	}
	
	int k=1;

	int** newArr = (int**)malloc(7 * sizeof(int));
	for(int i = 0; i < rows; i++){
		newArr[i] = (int*)malloc(7 * sizeof(int));
		for(int j=0; j<cols;j++){
			newArr[i][j]=arr[k];			
			k++;		
		}
	}
	
	return newArr;
	
		
}

void printArray(int rows, int cols, int** arr){
	for(int i = 0; i < rows; i++){
		for(int j=0; j<cols;j++){
			printf("%d", arr[i][j]);
		}
		printf("\n");
	} 
}



