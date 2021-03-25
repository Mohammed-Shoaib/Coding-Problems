/*
Problem Statement: https://leetcode.com/problems/find-the-highest-altitude/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int largestAltitude(vector<int>& gain) {
		int max_h, h;
		max_h = h = 0;
		
		for (int& x: gain) {
			h += x;
			max_h = max(h, max_h);
		}
		
		return max_h;
	}
};