/*
 * tests.cpp
 *
 *  Created on: Oct 3, 2019
 *      Author: kushal
 */

#include "tests.h"

tests::tests(){

}

tests::~tests(){

}

pawn p1 = pawn();
interaction i = interaction();

bool tests::runTests(){

	bool ok = true;
	cout << "These are tests!\n";

	bool ok1 = testFindPossiblePiecesToMove();
	cout << "This test finds and prints possible pieces on the board that can move\n" ;

	bool ok2 = testfindPossibleMoves();
	cout << "This test finds and prints possible moves for a particular piece\n";

	return ok && ok1 && ok2;
}

bool tests::testFindPossiblePiecesToMove(){
	bool result = true;

	int d1[nROWS][nCOLS] = {
			{ 0, 1, 0, 1, 0, 1, 0, 1 },
			{ 1, 0, 1, 0, 1, 0, 1, 0 },
			{ 0, 1, 0, 1, 0, 1, 0, 1 },
			{ 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 2, 0, 2, 0, 2, 0, 2, 0 },
			{ 0, 2, 0, 2, 0, 2, 0, 2 },
			{ 2, 0, 2, 0, 2, 0, 2, 0 }};

	int** testArr1 = p1.findPossiblePiecesToMove(d1, 1);
	i.printLocationArray(testArr1[0][1] + 1, testArr1);

	int d2[nROWS][nCOLS] = {
			{ 0, 1, 0, 1, 0, 1, 0, 1 },
			{ 1, 0, 1, 0, 1, 0, 1, 0 },
			{ 0, 1, 0, 1, 0, 0, 0, 1 },
			{ 0, 0, 0, 0, 1, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 2, 0, 2, 0, 2, 0, 2, 0 },
			{ 0, 2, 0, 2, 0, 2, 0, 2 },
			{ 2, 0, 2, 0, 2, 0, 2, 0 }};

	int** testArr2 = p1.findPossiblePiecesToMove(d2, 1);
	i.printLocationArray(testArr2[0][1]+1, testArr2);

	int d3[nROWS][nCOLS] = {
			{ 0, 1, 0, 1, 0, 1, 0, 1 },
			{ 1, 0, 1, 0, 1, 0, 1, 0 },
			{ 0, 1, 0, 1, 0, 0, 0, 1 },
			{ 0, 0, 0, 0, 1, 0, 0, 0 },
			{ 0, 0, 0, 2, 0, 0, 0, 0 },
			{ 2, 0, 0, 0, 2, 0, 2, 0 },
			{ 0, 2, 0, 2, 0, 2, 0, 2 },
			{ 2, 0, 2, 0, 2, 0, 2, 0 }};

	int** testArr3 = p1.findPossiblePiecesToMove(d3, 2);
	i.printLocationArray(testArr3[0][1]+1, testArr3);

	return result;

}

bool tests::testfindPossibleMoves(){
	bool result = true;

	int d1[nROWS][nCOLS] = {
			{ 0, 1, 0, 1, 0, 1, 0, 1 },
			{ 1, 0, 1, 0, 1, 0, 1, 0 },
			{ 0, 1, 0, 1, 0, 1, 0, 1 },
			{ 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 2, 0, 2, 0, 2, 0, 2, 0 },
			{ 0, 2, 0, 2, 0, 2, 0, 2 },
			{ 2, 0, 2, 0, 2, 0, 2, 0 }};

	int** testArr1 = p1.possibleMoves(d1, 3, 2,  1);
	i.printLocationArray(testArr1[0][1] + 1, testArr1);

	int d2[nROWS][nCOLS] = {
			{ 0, 1, 0, 1, 0, 1, 0, 1 },
			{ 1, 0, 1, 0, 1, 0, 1, 0 },
			{ 0, 1, 0, 1, 0, 1, 0, 1 },
			{ 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 2, 0, 2, 0, 2, 0, 2, 0 },
			{ 0, 2, 0, 2, 0, 2, 0, 2 },
			{ 2, 0, 2, 0, 2, 0, 2, 0 }};

	int** testArr2 = p1.possibleMoves(d2, 0, 5,  2);
	i.printLocationArray(testArr2[0][1] + 1, testArr2);

	int d3[nROWS][nCOLS] = {
			{ 0, 1, 0, 1, 0, 1, 0, 1 },
			{ 1, 0, 1, 0, 1, 0, 1, 0 },
			{ 0, 1, 0, 1, 0, 0, 0, 1 },
			{ 0, 0, 0, 0, 1, 0, 0, 0 },
			{ 0, 0, 0, 2, 0, 0, 0, 0 },
			{ 2, 0, 0, 0, 2, 0, 2, 0 },
			{ 0, 2, 0, 2, 0, 2, 0, 2 },
			{ 2, 0, 2, 0, 2, 0, 2, 0 }};

	int** testArr3 = p1.possibleMoves(d3, 4, 3,  1);
	i.printLocationArray(testArr3[0][1] + 1, testArr3);

	return result;

}

