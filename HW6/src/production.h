/*
 * production.h
 *
 *  Created on: Oct 2, 2019
 *      Author: kushal
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_

#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <fstream>

using namespace std;

class production {
public:
	production(int argc, char* argv[]);
	virtual ~production();
	bool runProduction(int argc, char* argv[]);


	int maxRoomsToSearch = 0;
	int limTreasure = 0;
	char filename[100];
	int numOfRooms = 0;
	//fstream fp;



};




#endif /* PRODUCTION_H_ */
