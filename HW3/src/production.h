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

//int test = 5;
#endif /* PRODUCTION_H_ */

bool production(int argc,char** argv);
int** readFileIntoHouse(int numOfRooms, FILE* fp);
int* readFileIntoTreasure(int numOfRooms, FILE* fp);
void print2DArray(int rows, int cols, int** arr);
void print1DArray(int rows, int* arr);
int** houseLayout(int rows, int cols, int* arr);
int* adjacentRooms(int** arr, int room, int noOfRooms);
int amtTreasure(int room, int* arr,int noOfRooms);
void interaction(int noOfRooms, int** houseGraph, int* fileArr, int treasureLimit, int maxRooms);
bool checkAdjRoomPresent(int* arr, int roomNo, int noOfRooms);
bool visited(int* arr, int roomNo, int count);
