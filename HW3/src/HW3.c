/*
 * HW3.c
 *
 *  Created on: Sep 10, 2019
 *      Author: kushal
 */

#include <stdio.h>
#include <stdlib.h>
#include "tests.h"
#include <stdbool.h>
#include "production.h"
#include "House.h"
#include "Kushal.h"

int main(int argc, char** argv){
	if(tests()){
		//printf("Tests Running!\n");
		//srand(2);
		printf("Let's do hw 3 !\n");
		printf("\n");
		production(argc,argv);
		
	}
	else{
		printf("Tests didn't pass!");	
	}
	return 0;
}

