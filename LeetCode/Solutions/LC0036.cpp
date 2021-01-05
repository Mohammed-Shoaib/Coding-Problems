/*
Problem Statement: https://leetcode.com/problems/valid-sudoku/
Time: O(n²)
Space: O(n²)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		int n = board.size();
		vector<unordered_set<int>> box(9);
		
		for (int i = 0; i < n; i++) {
			unordered_set<int> row;
			for (int j = 0; j < n; j++) {
				if (!isdigit(board[i][j]))
					continue;
				
				int x = 3 * (i / 3) + (j / 3);
				if (row.count(board[i][j]) || box[x].count(board[i][j]))
					return false;
				
				row.insert(board[i][j]);
				box[x].insert(board[i][j]);
			}
		}
		
		for (int i = 0; i < n; i++) {
			unordered_set<int> col;
			for (int j = 0; j < n; j++) {
				if (!isdigit(board[j][i]))
					continue;
				else if (col.count(board[j][i]))
					return false;
				col.insert(board[j][i]);
			}
		}
		
		return true;
	}
};