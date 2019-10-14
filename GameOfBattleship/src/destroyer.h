/*
 * destroyer.h
 *
 *  Created on: Oct 9, 2019
 *      Author: kushal
 */

#ifndef DESTROYER_H_
#define DESTROYER_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "ship.h"

class destroyer : public ship{
public:
	destroyer();
	~destroyer();
};


#endif /* DESTROYER_H_ */
