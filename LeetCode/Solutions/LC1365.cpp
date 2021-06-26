/*
Problem Statement: https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
Time: O(n • log n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
		int n = nums.size();
		unordered_map<int, int> mp;
		vector<int> counts(n), sorted(nums.begin(), nums.end());
		sort(sorted.begin(), sorted.end());
		
		for (int i = 0; i < n; i++)
			if (!mp.count(sorted[i]))
				mp[sorted[i]] = i;
		
		for (int i = 0; i < n; i++)
			counts[i] = mp[nums[i]];
		
		return counts;
	}
};