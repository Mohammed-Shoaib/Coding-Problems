/*
Problem Statement: https://leetcode.com/problems/single-number/
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int num: nums)
            res ^= num;
        return res;
    }
};