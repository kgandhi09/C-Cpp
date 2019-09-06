/*
 * production.h
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_
#include <stdbool.h>
#include <stdio.h>

bool production(int argc, char* argv[]);
int** make2Darray(int rows, int cols);
void printArray(int rows, int cols, int** array);
#endif /* PRODUCTION_H_ */
