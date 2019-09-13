/*
 * HW1.c
 *
 *  Created on: Sep 1, 2019
 *      Author: kushal
 */
#include "production.h"
#include "tests.h"
#include <stdio.h>
#include <stdlib.h>
#include "Kushal.h"

 int main(int argc, char* argv[]){

	printf("Hello World, Lets do HW1!!!\n");
	if(test()){
		printf("All tests passed!");

		production(argc,argv);

	}
	else{
		printf("Tests didn't pass!");
	}

	return EXIT_SUCCESS;
}

