/*
 * pawn.cpp
 *
 *  Created on: Oct 4, 2019
 *      Author: kushal
 */

#include "pawn.h"

pawn::pawn(){

}

pawn::~pawn(){

}

void pawn::move(int d[][nCOLS], int x1, int x2, int y1, int y2, int player){
	d[x1][y1] = 0;
	d[x2][y2] = player;
}

int** pawn::possibleMoves(int d[][nCOLS], int x, int y, int player){
	int count = 1;
	int count2 = 0;

	int** possibleMoves = new int*[10];

	for(int i = 0; i<nROWS; i++){
		for(int j = 0; j<nCOLS; j++){
			if (i == x && j == y){
				if(player == 1){

					if(d[i][j] == 1){
						if(!(j==7) && !(j==0)){
							if(d[i+1][j-1] == 0){
								possibleMoves[count] = new int[2];
								possibleMoves[count][0] = j-1;
								possibleMoves[count][1] = i+2;
								count++;
								count2++;
							}
							if(d[i+1][j+1] == 0){
								possibleMoves[count] = new int[2];
								possibleMoves[count][0] = j+1;
								possibleMoves[count][1] = i+2;
								count++;
								count2++;
							}
						}
						else{
							if(j==7){
								if(d[i+1][j-1] == 0){
									possibleMoves[count] = new int[2];
									possibleMoves[count][0] = j-1;
									possibleMoves[count][1] = i+2;
									count++;
									count2++;
								}
							}
							else if(j==0){
								if(d[i+1][j+1] == 0){
									possibleMoves[count] = new int[2];
									possibleMoves[count][0] = j+1;
									possibleMoves[count][1] = i+2;
									count++;
									count2++;
								}
							}

						}
					}
				}
				if(player == 2){

					if(d[i][j] == 2){
						if(!(j==7) && !(j==0)){
							if(d[i-1][j-1] == 0){
								possibleMoves[count] = new int[2];
								possibleMoves[count][0] = j-1;
								possibleMoves[count][1] = i;
								count++;
								count2++;
							}
							if(d[i-1][j+1] == 0){
								possibleMoves[count] = new int[2];
								possibleMoves[count][0] = j+1;
								possibleMoves[count][1] = i;
								count++;
								count2++;
							}
						}
						else{
							if(j==7){
								if(d[i-1][j-1] == 0){
									possibleMoves[count] = new int[2];
									possibleMoves[count][0] = j-1;
									possibleMoves[count][1] = i;
									count++;
									count2++;
								}
							}
							if(j==0){
								if(d[i-1][j+1] == 0){
									possibleMoves[count] = new int[2];
									possibleMoves[count][0] = j+1;
									possibleMoves[count][1] = i;
									count++;
									count2++;
								}
							}

						}
					}
				}
			}
		}
	}

	possibleMoves[0] = new int[2];
	possibleMoves[0][0] = count2;
	possibleMoves[0][1] = count2;
	return possibleMoves;
}

int** pawn::findPossiblePiecesToMove(int d[][nCOLS], int player){

	int count = 1;
	int count2 = 0;
	int** loc = new int*[20];



	for(int i = 0; i <nROWS;i++ ){
		for(int j = 0; j<nCOLS; j++){
			if(player == 1){
				if(d[i][j] == 1){

					if(!(j == 7) && !(j == 0)){
						if((d[i+1][j-1] == 0) || (d[i+1][j+1] == 0)){
							loc[count] = new int[2];
							loc[count][0] = j;
							loc[count][1] = i+1;
							count++;
							count2++;

						}
					}
					else{
						if(j==7){
							if((d[i+1][j-1] == 0)){
								loc[count] = new int[2];
								loc[count][0] = j;
								loc[count][1] = i+1;
								count++;
								count2++;
							}
						}
						if(j==0){
							if((d[i+1][j+1] == 0)){
								loc[count] = new int[2];
								loc[count][0] = j;
								loc[count][1] = i+1;
								count++;
								count2++;
							}
						}
					}
				}
			}
			if(player == 2){
				if(d[i][j] == 2){

					if(!(j == 7) && !(j == 0)){
						if((d[i-1][j-1] == 0) || (d[i-1][j+1] == 0)){
							loc[count] = new int[2];
							loc[count][0] = j;
							loc[count][1] = i+1;
							count++;
							count2++;

						}
					}
					else{
						if(j==7){
							if((d[i-1][j-1] == 0)){
								loc[count] = new int[2];
								loc[count][0] = j;
								loc[count][1] = i+1;
								count++;
								count2++;
							}
						}
						if(j==0){
							if((d[i-1][j+1] == 0)){
								loc[count] = new int[2];
								loc[count][0] = j;
								loc[count][1] = i+1;
								count++;
								count2++;
							}
						}
					}


				}
			}
		}

	}


	loc[0] = new int[2];
	loc[0][0] = count2;
	loc[0][1] = count2;
	return loc;

}


void pawn::print2DArray(int rows, int cols, int** arr){
	for(int i = 0; i < rows; i++){
		for(int j=0; j<cols;j++){
			printf("%2d", arr[i][j]);
		}
		printf("\n");
	}
}

void pawn::print1DArray(int rows, int* arr){
	for(int i = 0; i < rows; i++){
		printf("%3d", arr[i]);
	}
	printf("\n");
}

void pawn::printLocationArray(int rows, int** arr) {
	for (int i = 0; i < rows; i++) {
		//printf("Hello I am - %d\n", i);
		printf("%c%d\n", char('A' + arr[i][0]), arr[i][1]);
	}
	printf("\n");
}




