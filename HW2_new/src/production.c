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

bool production(int argc, char* argv[])
{
	bool answer = true;
	int** arr = (int**)malloc(2*2);
	arr=make2Darray(2,2);
	printArray(2,2,arr);
	return answer;
}

int** make2Darray(int rows, int cols){
	int theArray[rows][cols];
	for(int i = 0; i<rows; i++){
		for(int j = 0; j<cols; j++){
			theArray[rows][cols] = 0;
		}
	}

	return theArray;
}

void printArray(int rows, int cols, int** theArray){
	for(int i = 0; i<rows; i++){
		for(int j = 0; j<cols; j++){
			printf("%d", theArray[i][j]);
		}
	}
}


