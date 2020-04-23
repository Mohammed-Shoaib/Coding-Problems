/*
Problem Statement: https://leetcode.com/problems/missing-number/
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = nums.size() * (nums.size() + 1);
		sum /= 2;
		return sum - accumulate(nums.begin(), nums.end(), 0);
    }
};