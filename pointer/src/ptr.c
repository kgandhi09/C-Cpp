/*
 * ptr.c
 *
 *  Created on: Sep 3, 2019
 *      Author: kushal
 */

#include <stdio.h>

int main() {
	int x = 9;
	//printf("x is %d\n", x);

	x = 18;
	//printf("x is %d\n", x);

	int *aptr = &x;
	//printf("a pointer is %x\n", aptr);

	//printf("Now x is %d\n", *aptr);

	*aptr = 27;

	int y = 0;

	//printf("Now x is %d\n", x, *aptr);

	int numberArray[5];
	int *ptr = numberArray; // this is equivalent to *ptr = &numberArray[0];

	int v = 2;

	for(;ptr<&numberArray[5]; ptr++){
		*ptr = v;
		//printf("%d\n", *ptr);
		v= v * 2;

	}
	int i;
	for(i=0;i<5;i++){
		//printf("%d\n", i);
		printf("%d\n", numberArray[i]);
	}

}
