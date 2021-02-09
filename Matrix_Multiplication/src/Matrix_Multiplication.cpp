//============================================================================
// Name        : Matrix_Multiplication.cpp
// Author      : Kushal Gandhi
// Version     : 1.0
// Copyright   : This program is free to refer and use for anyone (c)
// Description : Matrix Multiplication in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

/**
 *This function is used to print a 2d-vector for debugging and displaying purposes
 *@param arr: a 2d vector whose elements are to be printed
 *
 */
void printArray(vector<vector<int>> arr){
	for(int i = 0; i < arr.size(); i++){
		for(int j = 0; j < arr[0].size(); j++){
			cout << arr[i][j] << "	";
		}
		cout << endl;
	}
}

/* Main Matrix mulitplication algorithm which uses a naive method to multiply the two matrices
 * Time complexity = O(n^3)
 * @param m1: a matrix in form of 2d vector with size lxm
 * @param m1: a matrix in form of 2d vector with size mxn
 * @return: a matrix in form of 2d vector with size lxn
 */
vector<vector<int>> naiveMatrixMultiplier1(vector<vector<int>> m1, vector<vector<int>> m2){

	vector<vector<int>> result;

	for(int i = 0; i < m1.size(); i++){
		vector<int> temp;
		int sum;
		for(int j = 0; j < m2[0].size(); j++){
			sum = 0;
			for(int k = 0; k < m1[0].size(); k++){
				sum += m1[i][k]*m2[k][j];
			}
			temp.push_back(sum);
		}
		result.push_back(temp);
	}
	return result;
}

/* Transpose algorithm to change places of rows and columns with each other
 * @param matrix: a matrix in form of 2d vector with size lxm
 * @return result: a transposed matrix in form of 2d vector with size mxl
 */
vector<vector<int>> transpose(vector<vector<int>> matrix){
	vector<vector<int>> result;

	int result_col = matrix.size();
	int result_row = matrix[0].size();

	for(int i = 0; i < result_row; i++){
		vector<int> temp;
		for(int j = 0; j < result_col; j++){
			temp.push_back(0);
		}
		result.push_back(temp);
	}
	for(int i = 0; i < result.size(); i++){
		for(int j = 0; j < result[0].size(); j++){
			result[i][j] = matrix[j][i];
		}
	}
	return result;
}

int main(){
	int m1_row;
	int m1_col;
	int m2_row;
	int m2_col;
	char flag;

	cout << "Welcome to the Matrix Multiplication program! "
			"You are about to input the dimensions of two matrices, "
			<< endl << "make sure the size of the column of the first matrix is equal to the size "
			"of the row of the second matrix :))" << endl << endl << "Enter 'Y' to continue ..." << endl;;

	cin >> flag;

	if(flag == 'Y'){

		/* Taking user keyboard input for first matrix's dimensions*/
		cout << endl << "Please enter the matrix 1 dimensions (row and column in separate lines): " << endl;
		cin >> m1_row >> m1_col;

		/* Taking user keyboard input for second matrix's dimensions*/
		cout << endl << "Please enter the matrix 2 dimensions (row and column in separate lines): " << endl;
		cin >> m2_row >> m2_col;

		if( m1_col != m2_row){
			cout << endl << "Sorry the column of first matrix and row of second matrix are not same, multiplication not applied!" << endl;
			return 0;
		}

		vector<vector<int>> m1;
		vector<vector<int>> m2;

		int m1_elem = 0;
		int m2_elem = 0;

		/* Taking user keyboard input for first matrix's elements and storing it in 2d vector m1*/
		cout << endl << "Please input elements for matrix 1 of size " << m1_row << "x" << m1_col << endl;
		cout << "        rxc:" << endl;
		for(int i = 0; i < m1_row; i++){
			vector<int> temp;
			for(int j = 0; j < m1_col; j++){
				cout << "Element " << i+1 << "x" << j+1 << ": ";
				cin >> m1_elem;
				temp.push_back(m1_elem);

			}
			m1.push_back(temp);
		}

		/* Taking user keyboard input for second matrix's elements and storing it in 2d vector m2*/
		cout << endl;
		cout << "Please input elements for matrix 2 of size " << m2_row << "x" << m2_col << endl;
		cout << "        rxc:" << endl;
		for(int i = 0; i < m2_row; i++){
			vector<int> temp;
			for(int j = 0; j < m2_col; j++){
				cout << "Element " << i+1 << "x" << j+1 << ": ";
				cin >> m2_elem;
				temp.push_back(m2_elem);
			}
			m2.push_back(temp);
		}

		/* Printing out 1st matrix*/
		cout << endl;
		cout << "Your Matrix 1 is: " << endl;
		printArray(m1);
		cout << endl;

		/* Printing out 2nd matrix*/
		cout << "Your Matrix 2 is: " << endl;
		printArray(m2);

		cout << endl;
		vector<vector<int>> m3 = naiveMatrixMultiplier1(m1, m2);

		/* Printing out the resultant matrix*/
		cout << endl;
		cout << "Resultant matrix using naive method with time complexity O(n^3) is: " << endl;
		printArray(m3);

		/* Calculating and Printing out the transpose of the resultant matrix*/
		cout << endl;
		vector<vector<int>> transpose_m3 = transpose(m3);
		cout << "Transpose of the resultant matrix is: " << endl;
		printArray(transpose_m3);
	}

	return 0;
}
