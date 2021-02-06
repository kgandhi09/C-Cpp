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

// Normal multiplication method with time complexity: O(n^3)
int** matrixMultiplier1(int** m1, int** m2, int r1, int c1, int r2, int c2){

	int** result;
	result = new int *[r1];


	for(int i = 0; i< r1; i++){
		result[i] = new int[c2];
	}

	for(int i = 0; i < r1; i++){
		for(int j = 0; j < c1; j++){
			result[i][j] = 0;
			for(int k = 0; k < c1; k++){
				result[i][j] += m1[i][k]*m2[k][j];
			}
		}
	}

	return result;
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

	cout << "Your Matrix 2 is: " << endl;
	printArray(m2, 4, 3);

	int** m3 = matrixMultiplier1(m1, m2, 3, 4, 4, 3);
	cout << endl;
	cout << "Your resultant matrix is: " << endl;
	printArray(m3, 3, 3);

	return 0;
}
