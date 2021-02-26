/*
Problem Statement: https://leetcode.com/problems/shuffle-the-array/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> shuffle(vector<int>& nums, int n) {
		vector<int> arr;
		for (int i = 0; i < n; i++) {
			arr.push_back(nums[i]);
			arr.push_back(nums[n + i]);
		}
		return arr;
	}
};