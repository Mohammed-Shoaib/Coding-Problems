/*
Problem Statement: https://leetcode.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool containsPattern(vector<int>& arr, int m, int k) {
		int len = 0, n = arr.size();
		for (int i = 0; i + m < n; i++) {
			if (arr[i] != arr[i + m])
				len = 0;
			else if (++len == m * (k - 1))
				return true;
		}
		return false;
	}
};