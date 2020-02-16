/*
Problem Statement: https://leetcode.com/problems/find-all-duplicates-in-an-array/
*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int pos;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            pos = abs(nums[i]) - 1;
            if (nums[pos] < 0)
                res.push_back(pos + 1);
            else
                nums[pos] *= -1;
        }
        return res;
    }
};