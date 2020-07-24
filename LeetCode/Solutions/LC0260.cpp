/*
Problem Statement: https://leetcode.com/problems/single-number-iii/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		vector<int> res(2);
		int mask = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
		mask = mask & (-mask);

		for (int& num: nums) {
			bool group = mask & num;
			res[group] ^= num;
		}

		return res;
	}
};