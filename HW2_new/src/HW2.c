/*
 * HW2.c
 *
 *  Created on: Sep 6, 2019
 *      Author: kushal
 */

#include <stdio.h>
#include <stdlib.h>
#include "production.h"
#include "tests.h"
#include <stdbool.h>

int main(int argc, char** argv){
	//int x = rand();
	if(tests()){
		printf("Tests Running!\n");
		srand(2);
		printf("Let's do hw 2 !\n");
		production(argc,argv);	
	}
	else{
		printf("Tests didn't pass!");	
	}
	return 0;
}
