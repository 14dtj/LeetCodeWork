/*
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
*/

#include "stdafx.h" 
#include<vector>
using namespace std;
class NumMatrix {
	//sum[i][j]=(0, 0)->(i,j)
	vector<vector<int>> sum;
	int row_len;
	int col_len;
public:
	NumMatrix(vector<vector<int>> &matrix) {
		row_len = matrix.size();
		col_len = matrix[0].size();
		sum = vector<vector<int>>(row_len, vector<int>(col_len, 0));
		sum[0][0] = matrix[0][0];
		for (int i = 1; i < col_len; i++) {
			sum[0][i] = matrix[0][i] + sum[0][i - 1];
		}
		for(int i = 1;i<row_len;i++){
			sum[i][0] = matrix[i][0] + sum[i-1][0];
		}
		for (int i = 1; i<row_len; i++) {
			for (int j = 1; j < col_len; j++) {
				sum[i][j] = matrix[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		if (row1 > 0 && col1 > 0) {
			return sum[row2][col2] - sum[row1 - 1][col2] - sum[row2][col1 - 1] + sum[row1 - 1][col1 - 1];
		}
		if (row1 > 0 && col1 == 0) {
			return sum[row2][col2] - sum[row1 - 1][col2];
		}
		if (row1 == 0 && col1 > 0) {
			cout << sum[row2][col2] << endl;
			cout << sum[row2][col1-1] << endl;
			return sum[row2][col2] - sum[row2][col1 - 1];
		}
		if (row1 == 0 && col1 == 0) {
			return sum[row2][col2];
		}
	}
};

int main()
{
	int data[4][3] = {
	{8,-4,5},
	{-1,4,4},
	{-2,3,1},
	{-4,4,3} };
	vector< vector<int> > matrix(4, vector<int>(3));
	for (int i = 0; i<matrix.size(); i++){
		for (int j = 0; j < matrix[i].size(); j++) {
			matrix[i][j] = data[i][j];
		}             
	}
	NumMatrix numMatrix(matrix);
	/*cout<<numMatrix.sumRegion(0, 1, 2, 3)<<endl;
	cout<<numMatrix.sumRegion(1, 2, 3, 4)<<endl;*/
	cout << numMatrix.sumRegion(0, 1, 0, 2) << endl;
	system("pause");
}


