/*
 * production.cpp
 *
 *  Created on: Oct 3, 2019
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
	int d[ROWS][COLS]={
	    {0,2,0,2,0,2,0,2},
	    {2,0,2,0,2,0,2,0},
	    {0,2,0,2,0,2,0,2},
	    {1,0,1,0,1,0,1,0},
	    {0,1,0,1,0,1,0,1},
	    {3,0,3,0,3,0,3,0},
	    {0,3,0,3,0,3,0,3},
		{3,0,3,0,3,0,3,0}};

	printDisplayFancy(d);
	return result;
}

void production::printDisplayFancy(int d[][COLS])
{

    printf("  +---+---+---+---+---+---+---+---+\n");

    for (int rr=0; rr<ROWS; ++rr)
    {
        printf("%d |", rr+1);
        for (int cc=0; cc<COLS; ++cc)
        {
            printf(" %c |", value2symbol(d[rr][cc]));
        }
        printf("\n");
        printf("  +---+---+---+---+---+---+---+---+\n");
    }

    printf("    a   b   c   d   e   f   g   h\n");
}

char production::value2symbol(int i)
{
    switch(i)
    {
  	case 0:
            return ' ';
        case 1:
            return 'E';
        case 2:
            return '$';
        case 3:
            return '@';
    }
    return ('?');
}

