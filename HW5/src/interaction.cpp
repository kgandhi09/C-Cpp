/*
 * interaction.cpp
 *
 *  Created on: Oct 3, 2019
 *      Author: kushal
 */

#include "interaction.h"
using namespace std;

interaction::interaction() {

}

interaction::~interaction() {

}

void interaction::runInteraction() {

	int d[nROWS][nCOLS] = {
			{ 0, 1, 0, 1, 0, 1, 0, 1 },
			{ 1, 0, 1, 0, 1, 0, 1, 0 },
			{ 0, 1, 0, 1, 0, 1, 0, 1 },
			{ 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 2, 0, 2, 0, 2, 0, 2, 0 },
			{ 0, 2, 0, 2, 0, 2, 0, 2 },
			{ 2, 0, 2, 0, 2, 0, 2, 0 }};

	pawn p = pawn();
	printBoard(d);
	printf("\n\n");
	int i = 0;
	int player;
	char c = ' ';
	int e = 0;


	while(1){
		if(i%2 == 0){
			player = 1;
			printf("!!!PLAYER 1 TURN!!!\n");
		}
		else if(i%2 == 1){
			player = 2;
			printf("!!!PLAYER 2 TURN!!!\n");
		}
		int** possiblePiecesToMove = p.findPossiblePiecesToMove(d, player);
		printf("Possible pieces to move are - \n");
		printLocationArray(possiblePiecesToMove[0][1]+1, possiblePiecesToMove);
		printf("Enter the piece to move - ");
		cin >> c >> e;
		cout << "\n";
		cout << "Possible Moves for the piece "<< c << e <<  " are - \n";
		int y1 = (c - '0') - 17;
		int x1 = e - 1;
		int** pM = p.possibleMoves(d, x1, y1, player);
		printLocationArray(pM[0][1]+1, pM);
		cout << "Enter position to move selected piece - ";
		cin >> c >> e;
		printf("\n");
		int y2 = (c - '0') - 17;
		int x2 = e - 1;
		p.move(d, x1, x2, y1, y2, player);
		printBoard(d);
		i++;
		printf("\n");
	}

}

void interaction::printBoard(int d[][nCOLS]) {

	printf("  +---+---+---+---+---+---+---+---+\n");

	for (int r = 0; r < nROWS; r++) {
		printf("%d |", r + 1);
		for (int c = 0; c < nCOLS; c++) {
			printf(" %c |", value2symbol(d[r][c]));
		}
		printf("\n");
		printf("  +---+---+---+---+---+---+---+---+\n");
	}

	printf("    A   B   c   D   E   F   G   H\n");

}

char interaction::value2symbol(int i) {
	switch (i) {
	case 0:
		return ' ';
	case 1:
		return 'R';
	case 2:
		return 'B';
	}
	return ('?');
}

void interaction::print2DArray(int rows, int cols, int** arr) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%2d", arr[i][j]);
		}
		printf("\n");
	}
}

void interaction::printLocationArray(int rows, int** arr) {
	for (int i = 1; i < rows; i++) {
		printf("%c%d\n", char('A' + arr[i][0]), arr[i][1]);
	}
	printf("\n");
}

void interaction::print1DArray(int rows, int* arr) {
	for (int i = 0; i < rows; i++) {
		printf("%3d", arr[i]);
	}
	printf("\n");
}

