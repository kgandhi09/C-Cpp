/*
 ============================================================================
 Name        : Spreadsheet.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/*
 ============================================================================
 Name        : HW1.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "Kushal.h"
#include "tests.h"
#include "production.h"

int main(int argc, char* argv[]) {

	int array[2][2] = {{1,2}, {2,1}};
	for(int j=0; j<2; j++){
		printf("\n");
		for(int k = 0; k<2; k++){
			printf("%d", array[j][k]);

		}

	}
	printf("\n");
	//int *ptr = array;


	for(int i=0; i<2; i++){
		for(int s = 0; s<2; s++){
			array[i][s] = 0;
		}
	}

	for(int l=0; l<2; l++){
			printf("\n");
			for(int m = 0; m<2; m++){
				printf("%d", array[l][m]);

			}
	}
	printf("\n");


	//printf("Pointer is %d\n", *ptr);
	puts("!!!Let's do Lab2!!!");
	if(tests())
	{
		production(argc, argv);
	}
	else
	{
		 puts("Tests did not pass.");
	}
	return EXIT_SUCCESS;
}
