/*
 * production.cpp
 *
 *  Created on: Oct 3, 2019s
 *      Author: kushal
 */

#include "production.h"



production::production(int argc, char* argv[]){

}

production::~production(){

}

bool production::runProduction(int argc, char* argv[]){
	bool result = true;
	cout << "This is production!\n";
	i.runInteraction();
	return result;
}

