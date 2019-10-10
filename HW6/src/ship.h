/*
 * ship.h
 *
 *  Created on: Oct 9, 2019
 *      Author: kushal
 */

#ifndef SHIP_H_
#define SHIP_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

class ship{
public:
	ship();
	virtual ~ship();
	char symbol;
	int length;
	char* name;
};


#endif /* SHIP_H_ */
