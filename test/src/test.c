/*
 * test.c
 *
 *  Created on: Sep 7, 2019
 *      Author: kushal
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char** argv){
	printf("code started\n");
	production(argc, argv);
}

bool production(int argc, char* argv[])
{
	int** arr = make2Darray(3,3);
	printArray(3,3,arr);	
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

void printArray(int rows, int cols, int** theArray){
	for(int i = 0; i<rows; i++){
		printf("%s", "|");
		for(int j = 0; j<cols; j++){
			printf("%2d",theArray[i][j]);
			printf("%2s", "|");
		}

		printf("\n");
	}
}
