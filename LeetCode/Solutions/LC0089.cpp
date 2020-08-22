/*
Problem Statement: https://leetcode.com/problems/gray-code/
Time: O(2ⁿ)
Space: O(2ⁿ)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> grayCode(int n) {
		int len = 1 << n;
		vector<int> gray;
		for (int i = 0; i < len; i++)
			gray.push_back(i ^ (i >> 1));
		return gray;
	}
};