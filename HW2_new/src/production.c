/*
 * production.c
 *
 *  Created on: Sep 6, 2019
 *      Author: kushal
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "production.h"
#include <string.h>

int nRows=3;
int nCols=3;

bool production(int argc, char* argv[])
{
	bool answer = true;
	//char* ePtr=(char*)malloc(sizeof(char*));
	//int nRows_l=strtol(argv[1],&ePtr,10);
	//int nCols_l=strtol(argv[2],&ePtr,10);
	//nRows=(int)nRows_l;
	//nCols=(int)nCols_l;
	
	int** arr = make2Darray(nRows,nCols);
	
	
	moveMarker(arr, nRows, nCols);
	


	return answer;
}

void moveMarker(int** arr,int rows, int cols){
	
	for(int i = 0; i<10; i++){
		int nr=randInt(rows);
		int nc=randInt(cols);
		placeMarker(1, nr, nc, arr);
		printf("\n");			
		printArray(rows,cols,arr);
		printf("\n");
	} 
}

int** make2Darray(int rows, int cols){
	int** theArray = (int**)malloc(rows * sizeof(int));

	for(int i = 0; i<rows; i++) {
		theArray[i] = (int*)malloc(cols * sizeof(int));
		for(int j = 0; j<cols; j++){
			theArray[i][j] = 0;
		}
	}

	return theArray;
}


void placeMarker(int marker, int row, int col, int** theArray){
	
	int* markerPosArr = getMarkerPos(theArray, nRows, nCols);
	
	theArray[row][col] = marker;
	printf("abc\n");	
	if (markerPosArr!=NULL){ // if the array does have a marker
		if(markerPosArr[0]!=row || markerPosArr[1]!=col){
			theArray[markerPosArr[0]][markerPosArr[1]] = 0;
		}


	}

}

int* getMarkerPos(int** arr, int rows, int cols){
	int* pos = (int*)malloc(sizeof(int)*2);
	for(int i = 0; i<rows; i++){
		for(int j = 0; j<rows; j++){
			if (arr[i][j] == 1){
				pos[0]= i; 
				pos[1]= j; 
				return pos;
			}

		}
	}
	return NULL;
}

int randInt(int val){
	int x = rand();
	x = x%(val+1);
	return x;
}

//"%c[4mHello world\n%c[0m" - To underline the print

void printArray(int rows, int cols, int** theArray){
	printf("%s\n", "-------------");
	for(int i = 0; i<rows; i++){
		printf("%c", '|');
		for(int j = 0; j<cols; j++){
			printf("%2d",theArray[i][j]);
			printf("%2c", '|');
		}
		printf("\n");
		printf("%s\n", "-------------");



	}
}

