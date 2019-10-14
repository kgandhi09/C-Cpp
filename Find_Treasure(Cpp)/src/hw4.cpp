/*
 * hw4.cpp
 *
 *  Created on: Sep 26, 2019
 *      Author: kushal
 */
#include <iostream>
using namespace std;
#include "production.h"
#include "tests.h"

int main(int argc, char* argv[]) {
	tests ts = tests();
	if(ts.runTests()){
		production p = production(argc, argv);
		p.runProduction(argc, argv);
	}
	return 1;
}



