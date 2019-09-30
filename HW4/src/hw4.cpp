/*
 * hw4.cpp
 *
 *  Created on: Sep 26, 2019
 *      Author: kushal
 */
#include <iostream>
using namespace std;
#include "production.h"

int main(int argc, char* argv[]) {
	production p = production(argc, argv);
	p.runProduction(argc, argv);
	return 1;
}



