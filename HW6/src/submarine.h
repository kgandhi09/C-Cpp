/*
 * submarine.h
 *
 *  Created on: Oct 9, 2019
 *      Author: kushal
 */

#ifndef SUBMARINE_H_
#define SUBMARINE_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "ship.h"

class submarine : public ship{
public:
	submarine();
	~submarine();
	//int length = 3;
};

#endif /* SUBMARINE_H_ */
