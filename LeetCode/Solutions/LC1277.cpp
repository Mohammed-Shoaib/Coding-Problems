/*
Problem Statement: https://leetcode.com/problems/count-square-submatrices-with-all-ones/
*/

class Solution {
public:
    int countSquares(vector< vector<int> >& matrix) {
		int squares = 0;
		
		// Dynamic Programming
		for (int i = 1; i < matrix.size(); i++)
			for (int j = 1; j < matrix[i].size(); j++) 
				if (matrix[i][j])
					matrix[i][j] = 1 + min(matrix[i - 1][j - 1], min(matrix[i - 1][j], matrix[i][j - 1]));
		
		// Sum the results
		for (int i = 0; i < matrix.size(); i++)
			squares += accumulate(matrix[i].begin(), matrix[i].end(), 0);
		
		return squares;
    }
};