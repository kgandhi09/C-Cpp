/*
 * battleship.h
 *
 *  Created on: Oct 9, 2019
 *      Author: kushal
 */

#ifndef BATTLESHIP_H_
#define BATTLESHIP_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "ship.h"

class battleship : public ship{
public:
	battleship();
	~battleship();
	//int length = 4;
};



#endif /* BATTLESHIP_H_ */
