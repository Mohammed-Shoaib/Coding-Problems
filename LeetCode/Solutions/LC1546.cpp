/*
Problem Statement: https://leetcode.com/problems/maximum-number-of-non-overlapping-subarrays-with-sum-equals-target/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int maxNonOverlapping(vector<int>& nums, int target) {
		int cnt, sum;
		unordered_map<int, int> mp;
		cnt = sum = mp[0] = 0;

		for (int& num: nums) {
			sum += num;
			if (mp.count(sum - target))
				cnt = max(mp[sum - target] + 1, cnt);
			mp[sum] = cnt;
		}

		return cnt;
	}
};