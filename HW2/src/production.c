/*
 * production.c
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */
#include <stdio.h>
#include <stdlib.h>
#include "production.h"
bool production(int argc, char* argv[])
{
	bool answer = true;
	return answer;
}

int** make2Darray(int rows, int cols){

	int theArray[rows][cols];
	//int* theArray = (int*)malloc(rows*cols*sizeof(int));
	for(int i = 0; i<rows; i++){
		for(int j = 0; j<cols; j++){
			theArray[i][j] = 0;
		}

	}

	return theArray;

}

void printArray(int rows, int cols, int** array){
	for(int i = 0; i<rows; i++){
		for(int j = 0; j<cols; j++){
			puts(array[i][j]);
		}
		puts("\n");
	}

}
