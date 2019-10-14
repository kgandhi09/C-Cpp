/*
 * controller.h
 *
 *  Created on: Oct 1, 2019
 *      Author: kushal
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include <iostream>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

using namespace std;

class controller {
public:
	controller();
	virtual ~controller();
	int** readFileIntoHouse(int numOfRooms,  FILE* fp);
	int* readFileIntoTreasure(int numOfRooms, FILE* fp);
	void print2DArray(int rows, int cols, int** arr);
	void print1DArray(int rows, int* arr);
	int* adjacentRooms(int** arr, int room, int noOfRooms);
	int amtTreasure(int room, int* arr, int noOfRooms);
	bool checkAdjRoomPresent(int* arr, int roomNo, int noOfRooms);
	bool visited(int* arr, int roomNo, int count);

};




#endif /* CONTROLLER_H_ */
