/*
 * production.h
 *
 *  Created on: Sep 11, 2019
 *      Author: kushal
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#endif /* PRODUCTION_H_ */

bool production(int argc,char** argv);
int* readFileIntoArray(int rows, int cols, int nElements, FILE* fp);
void printArray(int rows, int cols, int** arr);
void print1DArray(int rows, int* arr);
