/*
 * hw6.cpp
 *
 *  Created on: Oct 2, 2019
 *      Author: kushal
 */

#include <iostream>
using namespace std;
#include "production.h"
#include "tests.h"

int main(int argc, char* argv[]) {
	tests ts = tests();
	if(ts.runTests()){
		cout << "Let's do hw6\n";
		production p = production(argc, argv);
		p.runProduction(argc, argv);
	}
	return 1;
}


