/*
Problem Statement: https://leetcode.com/problems/range-sum-query-immutable/
Time: O(n • log n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class NumArray {
private:
	vector<int> sum;
public:
	NumArray(vector<int>& nums) : sum(nums.size() + 1) {
		partial_sum(nums.begin(), nums.end(), sum.begin() + 1);
	}
	
	int sumRange(int i, int j) {
		return sum[j + 1] - sum[i];
	}
};