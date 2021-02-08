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
int col1 = -1;

struct strassenSubMatrix
{
	vector<vector<int>> m1;
	vector<vector<int>> m2;
	vector<vector<int>> m3;
	vector<vector<int>> m4;

};

/*
 * arr: v2d vector
 */
void printArray(vector<vector<int>> arr){
	for(int i = 0; i < arr.size(); i++){
		for(int j = 0; j < arr[0].size(); j++){
			cout << arr[i][j] << "	";
		}
		cout << endl;
	}
}

// Normal multiplication method with time complexity: O(n^3)
vector<vector<int>> naiveMatrixMultiplier1(vector<vector<int>> m1, vector<vector<int>> m2){

	vector<vector<int>> result;

	for(int i = 0; i < m1.size(); i++){
		vector<int> temp;
		int sum;
		for(int j = 0; j < m1[0].size(); j++){
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

	cout << "Please enter the matrix 1 dimensions (row and column in separate lines): " << endl;
	cin >> m1_row >> m1_col;

	cout << endl << "Please enter the matrix 2 dimensions (row and column in separate lines): " << endl;
	cin >> m2_row >> m2_col;

	vector<vector<int>> m1;
	vector<vector<int>> m2;

	int m1_elem = 0;
	int m2_elem = 0;

	cout << "Please input elements for matrix 1 of size " << m1_row << "x" << m1_col << endl;
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
	cout << endl;
	cout << "Your Matrix 1 is: " << endl;
	printArray(m1);
	cout << endl;

	cout << "Your Matrix 2 is: " << endl;
	printArray(m2);

	cout << endl;
	vector<vector<int>> m3 = naiveMatrixMultiplier1(m1, m2);

	cout << endl;
	cout << "Resultant matrix using naive method with time complexity O(n^3) is: " << endl;
	printArray(m3);

	cout << endl;
	vector<vector<int>> transpose_m3 = transpose(m3);
	cout << "Transpose of the resultant matrix is: " << endl;
	printArray(transpose_m3);

	return 0;
}
