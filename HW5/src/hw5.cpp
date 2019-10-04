/*
 * hw5.cpp
 *
 *  Created on: Oct 3, 2019
 *      Author: kushal
 */

#include <iostream>
using namespace std;
#include "production.h"
#include "tests.h"

int main(int argc, char* argv[]) {
	tests ts = tests();
	if(ts.runTests()){
		cout << "Lets do hw5!\n";
		production p = production(argc, argv);
		p.runProduction(argc, argv);
	}
	return 1;
}



