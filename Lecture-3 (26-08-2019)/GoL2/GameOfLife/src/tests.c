/*
 * tests.c
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */

#include "tests.h"
#include "production.h"
#include "Board.h"

bool tests()
{
	bool answer = false;
	bool ok1 =  testDisplayBoard();
	answer = ok1;
	return answer;
}

bool testDisplayBoard()
{
	puts("starting testDisplayBoard");
	fflush(stdout);
	bool ok = false;
	//we need to have a board before we can display it.
	//the boards can be represented in arrays, one dimension for row, one for column
	//we could even have a dimension for the past, current and future boards.
	//this is a test case
	int nRows = 6;
	int nCols = 8;

	int theBoards[nBOARDS][nRows][nCols];
	//we set one board to a known pattern
	//we'll print out the pattern to the console
	//checking by eye.
	//set the known pattern:
	puts("initializing the board");
	fflush(stdout);
	for(int board = 0; board<nBOARDS; board++)
	{
		for(int row=0; row<nRows; row++)
		{
			for(int col=0; col<nCols; col++)
			{
				theBoards[board][row][col] = (row==col); //diagonal matrix
			}
		}
	}
	int* b0 = &(theBoards[0][0][0]);
	int* b1 = &(theBoards[1][0][0]);
	int* b2 = &(theBoards[2][0][0]);
	//here's the test
	puts("Here's board 0");
    displayBoard(b0, nRows, nCols);
    puts("Here's board 1");
    displayBoard(b1, nRows, nCols);
    puts("Here's board 2");
    displayBoard(b2, nRows, nCols);

    printf("Did they look like diagonal matrices?(y or other letter): ");
    fflush(stdout);
    char a = getchar();
    if (a == 'y')
    {
    	ok = true;
    }

	return ok;
}
