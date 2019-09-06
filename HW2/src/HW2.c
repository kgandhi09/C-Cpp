/*
 ============================================================================
 Name        : HW2.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "tests.h"
#include "production.h"
#include "TMSName.h"

//here are some external variables, see Kernighan and Richie, pp. 31, 32

int main(int argc, char* argv[]) {

	puts("!!!Let's do the spreadsheet example!!!");  //prints !!!Hello World!!!
	if(tests())
	{
		puts("Tests done!");
		production(argc, argv);
		int** arr = make2Darray(2,2);
		printArray(2,2,arr);
	}
	else
	{
		 puts("Tests did not pass.");
	}
	return EXIT_SUCCESS;
}
