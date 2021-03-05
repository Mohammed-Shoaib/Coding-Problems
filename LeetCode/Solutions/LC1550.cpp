/*
Problem Statement: https://leetcode.com/problems/three-consecutive-odds/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool threeConsecutiveOdds(vector<int>& arr) {
		int cnt = 0;
		for (int& x: arr) {
			if (x & 1)
				cnt++;
			else
				cnt = 0;
			if (cnt == 3)
				return true;
		}
		return false;
	}
};