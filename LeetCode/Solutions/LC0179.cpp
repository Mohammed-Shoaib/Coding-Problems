/*
Problem Statement: https://leetcode.com/problems/largest-number/
Time: O(n • log n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
private:
	static int64_t convert(vector<int> nums) {
		int64_t num = 0;
		for (int x: nums) {
			int copy = x;
			while (copy) {
				num *= 10;
				copy /= 10;
			}
			num += x;
		}
		return num;
	}
	
	static bool compare(int l, int r) {
		int64_t lr, rl;
		if (l == 0 || r == 0)
			return l > r;
		lr = convert({l, r});
		rl = convert({r, l});
		return lr > rl;
	}

public:
	string largestNumber(vector<int>& nums) {
		string s;
		sort(nums.begin(), nums.end(), compare);
		if (!nums.empty() && nums[0] == 0)
			return "0";
		for (int& x: nums)
			s += to_string(x);
		return s;
	}
};