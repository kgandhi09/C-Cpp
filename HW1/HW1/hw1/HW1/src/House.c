/*
 * House.c
 *
 *  Created on: Aug 30, 2019
 *      Author: kushal
 */

#include "House.h"

int getNumberOfRooms(){
	int nRooms = countRooms();
	return nRooms;
}

int getNewRoom(){
	int aRoom = getFirstRoom();
	return aRoom;
}

