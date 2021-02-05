//============================================================================
// Name        : Matrix_Multiplication.cpp
// Author      : Kushal Gandhi
// Version     : 1.0
// Copyright   : This program is free to refer and use for anyone (c)
// Description : Matrix Multiplication in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int col1 = -1;


void printArray(int** arr, int row, int col){
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cout << arr[i][j] << "	";
		}
		cout << endl;
	}
}

int matrixMultiplier(int** m1, int** m2){
//	int** result;
	int result_row = sizeof(m1)/sizeof(int);
	return result_row;
}

int main(){
	int** m1;
	int** m2;


	m1 = new int *[3];
	m2 = new int *[4];

	for(int i = 0; i < 3; i++){
		m1[i] = new int[4];
	}
	for(int i = 0; i < 4; i++){
		m2[i] = new int[3];
	}

	cout << "Please input elements for matrix 1 of size (3*4)" << endl;
	cout << "        rxc:" << endl;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 4; j++){
			cout << "Element " << i+1 << "x" << j+1 << ": ";
			cin >> m1[i][j];
		}
	}
	cout << endl;
	cout << "Please input elements for matrix 2 of size (4*3)" << endl;
	cout << "        rxc:" << endl;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 3; j++){
			cout << "Element " << i+1 << "x" << j+1 << ": ";
			cin >> m2[i][j];
		}
	}
	cout << endl;


	cout << "Your Matrix 1 is: " << endl;
	printArray(m1, 3, 4);
	cout << endl;

	cout << "Your Matrix 21 is: " << endl;
	printArray(m2, 4, 3);

	int m1_rowSize = matrixMultiplier(m1, m2);
	cout << endl << m1_rowSize << endl;
	return 0;
}
