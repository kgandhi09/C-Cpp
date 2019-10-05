/*
 * production.h
 *
 *  Created on: Oct 3, 2019
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

class production{
public:

	#define ROWS 8
	#define COLS 8
	production(int argc, char* argv[]);
	virtual ~production();
	bool runProduction(int argc, char* argv[]);

	interaction i = interaction();

};


#endif /* PRODUCTION_H_ */
