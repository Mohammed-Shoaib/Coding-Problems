/*
Problem Statement: https://leetcode.com/problems/beautiful-arrangement-ii/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> constructArray(int n, int k) {
		int l = 1, r = n;
		vector<int> arr(n);
		
		for (int i = 0; i < n; i++) {
			if (k == 1 || (k & 1))
				arr[i] = l++;
			else
				arr[i] = r--;
			k = max(1, k - 1);
		}
		
		return arr;
	}
};