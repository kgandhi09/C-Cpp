/*
 * production.h
 *
 *  Created on: Sep 6, 2019
 *      Author: kushal
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_
#include <stdbool.h>


bool production(int argc, char* argv[]);
int** make2Darray(int rows, int cols);
void printArray(int rows, int cols, int** theArray);
int* getMarkerPos(int** arr, int rows, int cols);
void placeMarker(int marker, int row, int col, int** theArray);
void moveMarker(int** arr,int rows, int cols);
int randInt(int val);

#endif /* PRODUCTION_H_ */
