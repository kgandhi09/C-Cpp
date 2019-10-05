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

void pawn::move(int d[][nCOLS], int** arr, int player){
	char x = ' ';
	int y = 0;
	//printf("Enter the piece number to move - ");
	//scanf("%c%d", &x,&y);
	//printf("%c%d\n", x,y);
	int** pm = possibleMoves(d, 2, 7, 1);
	//print2DArray(2,2, pm);
	printLocationArray(1, pm);


}

int** pawn::possibleMoves(int d[][nCOLS], int x, int y, int player){
	int count = 0;
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
							}
							if(d[i+1][j+1] == 0){
								possibleMoves[count] = new int[2];
								possibleMoves[count][0] = j+1;
								possibleMoves[count][1] = i+2;
								count++;
							}
						}
						else{
							if(j==7){
								if(d[i+1][j-1] == 0){
									possibleMoves[count] = new int[2];
									possibleMoves[count][0] = j-1;
									possibleMoves[count][1] = i+2;
									count++;
								}
							}
							else if(j==0){
								if(d[i+1][j+1] == 0){
									possibleMoves[count] = new int[2];
									possibleMoves[count][0] = j+1;
									possibleMoves[count][1] = i+2;
									count++;
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
							}
							if(d[i-1][j+1] == 0){
								possibleMoves[count] = new int[2];
								possibleMoves[count][0] = j+1;
								possibleMoves[count][1] = i;
								count++;
							}
						}
						else{
							if(j==7){
								if(d[i-1][j-1] == 0){
									possibleMoves[count] = new int[2];
									possibleMoves[count][0] = j-1;
									possibleMoves[count][1] = i;
									count++;
								}
							}
							if(j==0){
								if(d[i-1][j+1] == 0){
									possibleMoves[count] = new int[2];
									possibleMoves[count][0] = j+1;
									possibleMoves[count][1] = i;
									count++;
								}
							}

						}
					}
				}
			}
		}
	}

	return possibleMoves;
}

int** pawn::findPossiblePiecesToMove(int d[][nCOLS], int player){

	int count = 0;
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

						}
					}
					else{
						if(j==7){
							if((d[i+1][j-1] == 0)){
								loc[count] = new int[2];
								loc[count][0] = j;
								loc[count][1] = i+1;
								count++;
							}
						}
						if(j==0){
							if((d[i+1][j+1] == 0)){
								loc[count] = new int[2];
								loc[count][0] = j;
								loc[count][1] = i+1;
								count++;
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

						}
					}
					else{
						if(j==7){
							if((d[i-1][j-1] == 0)){
								loc[count] = new int[2];
								loc[count][0] = j;
								loc[count][1] = i+1;
								count++;
							}
						}
						if(j==0){
							if((d[i-1][j+1] == 0)){
								loc[count] = new int[2];
								loc[count][0] = j;
								loc[count][1] = i+1;
								count++;
							}
						}
					}


				}
			}
		}

	}



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


