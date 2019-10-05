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
	p.printBoard(d);
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
		//printf(" size of possible %d\n", sizeof(possiblePiecesToMove)/2);
		printf("Possible pieces to move are - \n");
		printLocationArray(4, possiblePiecesToMove);
		printf("Enter the piece to move - ");
		cin >> c >> e;
		cout << "\n";
		cout << "Possible Moves for the piece "<< c << e <<  " are - \n";
		int y1 = (c - '0') - 17;
		int x1 = e - 1;
		int** pM = p.possibleMoves(d, x1, y1, player);
		printLocationArray(2, pM);
		//printf("size of PM %d\n", sizeof(pM)/2);
		cout << "Enter position to move selected piece - ";
		cin >> c >> e;
		printf("\n");
		int y2 = (c - '0') - 17;
		int x2 = e - 1;
		//cout << "selected pos is " << x2 << y2 << "\n";
		p.move(d, x1, x2, y1, y2, player);
		cout << "Hello\n";
		p.printBoard(d);
		i++;
		printf("\n");
	}

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
	for (int i = 0; i < rows; i++) {
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

