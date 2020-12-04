/*
Problem Statement: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
*/

class Solution {
public:
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		int pos;
		vector<int> res;
		for (int i = 0; i < nums.size(); i++) {
			pos = abs(nums[i]) - 1;
			nums[pos] = -1 * abs(nums[pos]);
		}
		for (int i = 0; i < nums.size(); i++)
			if (nums[i] > 0)
				res.push_back(i + 1);
		return res;
	}
};