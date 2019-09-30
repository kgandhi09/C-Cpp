/*
 * interaction.h
 *
 *  Created on: Sep 29, 2019
 *      Author: kushal
 */

#ifndef INTERACTION_H_
#define INTERACTION_H_

#include <iostream>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "production.h"

class interaction {
public:
	interaction(int noOfRooms, int** houseGraph, int* treasures, int treasureLimit, int maxRooms);
	virtual ~interaction();
	void runInteraction(int argc, char* argv[], int noOfRooms, int** houseGraph, int* treasures, int treasureLimit, int maxRooms);

};



#endif /* INTERACTION_H_ */
