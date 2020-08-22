/*
Problem Statement: https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
*/

class Solution {
public:
	bool isPossibleDivide(vector<int>& nums, int k) {
		int val, cnt;
		unordered_map<int, int> freq;
		
		for (int num: nums)
			freq[num]++;
		
		for (auto it: freq) {
			tie(val, cnt) = it;
			if (cnt == 0)
				continue;
			for (int i = val + 1; i - val < k; i++) {
				if (freq[i] < cnt)
					return false;
				freq[i] -= cnt;
			}
		}
		
		return true;
	}
};