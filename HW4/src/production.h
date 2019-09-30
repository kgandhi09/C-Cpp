/*
 * production.h
 *
 *  Created on: Sep 26, 2019
 * cpp
 *      Author: kushal
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_


#include <iostream>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <fstream>
#include "interaction.h"
using namespace std;

class production {
public:
	production(int argc, char* argv[]);
	virtual ~production();
	bool runProduction(int argc, char* argv[]);
	int** readFileIntoHouse(int numOfRooms,  FILE* fp);
	int* readFileIntoTreasure(int numOfRooms, FILE* fp);
	void print2DArray(int rows, int cols, int** arr);
	void print1DArray(int rows, int* arr);
	int* adjacentRooms(int** arr, int room, int noOfRooms);
	int amtTreasure(int room, int* arr, int noOfRooms);
	bool checkAdjRoomPresent(int* arr, int roomNo, int noOfRooms);
	bool visited(int* arr, int roomNo, int count);

	int maxRoomsToSearch = 0;
	int limTreasure = 0;
	char filename[100];
	int numOfRooms = 0;
	//fstream fp;
};


#endif /* PRODUCTION_H_ */
