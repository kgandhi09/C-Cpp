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


struct returnDataType
{
	int** m3;
	int m3_row;
	int m3_col;
};

void printArray(int** arr, int row, int col){
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cout << arr[i][j] << "	";
		}
		cout << endl;
	}
}

// Normal multiplication method with time complexity: O(n^3)
returnDataType naiveMatrixMultiplier1(int** m1, int** m2, int r1, int c1, int r2, int c2){

	int m3_row = r1;
	int m3_col = c2;
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

	returnDataType m3 = {result, m3_row, m3_col};
	return m3;
}

int main(){
	int m1_row;
	int m1_col;
	int m2_row;
	int m2_col;

	cout << "Please enter the matrix 1 dimensions (row and column in separate lines): " << endl;
	cin >> m1_row >> m1_col;

	cout << endl << "Please enter the matrix 2 dimensions (row and column in separate lines): " << endl;
	cin >> m2_row >> m2_col;

	int** m1;
	int** m2;

	m1 = new int *[m1_row];
	m2 = new int *[m2_row];

	for(int i = 0; i < m1_row; i++){
		m1[i] = new int[m1_col];
	}
	for(int i = 0; i < m2_row; i++){
		m2[i] = new int[m2_col];
	}

	cout << "Please input elements for matrix 1 of size " << m1_row << "x" << m1_col << endl;
	cout << "        rxc:" << endl;
	for(int i = 0; i < m1_row; i++){
		for(int j = 0; j < m1_col; j++){
			cout << "Element " << i+1 << "x" << j+1 << ": ";
			cin >> m1[i][j];
		}
	}
	cout << endl;
	cout << "Please input elements for matrix 2 of size " << m2_row << "x" << m2_col << endl;
	cout << "        rxc:" << endl;
	for(int i = 0; i < m2_row; i++){
		for(int j = 0; j < m2_col; j++){
			cout << "Element " << i+1 << "x" << j+1 << ": ";
			cin >> m2[i][j];
		}
	}
	cout << endl;


	cout << "Your Matrix 1 is: " << endl;
	printArray(m1, m1_row, m1_col);
	cout << endl;

	cout << "Your Matrix 2 is: " << endl;
	printArray(m2, m2_row, m2_col);

	returnDataType resultant_normal = naiveMatrixMultiplier1(m1, m2, m1_row, m1_col, m2_row, m2_col);
	int** m3 = resultant_normal.m3;
	int m3_row = resultant_normal.m3_row;
	int m3_col = resultant_normal.m3_col;

	cout << endl;
	cout << "Resultant matrix using naive method with time complexity O(n^3) is: " << endl;
	printArray(m3, m3_row, m3_col);

	return 0;
}
