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



int getNumberOfRooms(){
	int nRooms = countRooms();
	return nRooms;
}

int getNewRoom(){
	int aRoom = getFirstRoom();
	return aRoom;
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
