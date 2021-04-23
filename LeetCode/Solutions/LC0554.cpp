/*
Problem Statement: https://leetcode.com/problems/brick-wall/
Time: O(n • width)
Space: O(width)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int leastBricks(vector<vector<int>>& wall) {
		int cnt = 0, n = wall.size();
		unordered_map<int, int> freq;
		
		for (int i = 0; i < n; i++) {
			int width = 0;
			for (int& x: wall[i]) {
				if (width)
					cnt = max(++freq[width], cnt);
				width += x;
			}
		}
		
		return n - cnt;
	}
};