/*
Problem Statement: https://leetcode.com/problems/shift-2d-grid/
Time: O(m • n)
Space: O(m • n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
		int size, m = grid.size(), n = grid[0].size();
		size = m * n;
		k %= size;
		reverse(0, size - k, grid);
		reverse(size - k, size, grid);
		reverse(0, size, grid);
		return grid;
	}
	
	void reverse(int low, int high, vector<vector<int>>& grid) {
		int n = grid[0].size();
		high--;
		while (low < high) {
			swap(grid[low / n][low % n], grid[high / n][high % n]);
			low++;
			high--;
		}
	}
};