/*
Problem Statement: https://leetcode.com/problems/height-checker/
Time: O(n • log n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int heightChecker(vector<int>& heights) {
		int moves = 0, n = heights.size();
		vector<int> order(heights);
		
		sort(order.begin(), order.end());
		for (int i = 0; i < n; i++)
			moves += (heights[i] != order[i]);
		
		return moves;
	}
};