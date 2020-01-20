/*
Problem Statement: https://leetcode.com/problems/permutations/
*/

class Solution {
public:
    vector< vector<int> > permute(vector<int>& nums) {
        vector< vector<int> > perms;
        sort(nums.begin(), nums.end());
        
        do {
            perms.push_back(nums);
        } while(next_permutation(nums));
        
        return perms;
    }

    bool next_permutation(vector<int>& nums) {
        int i, j, n;
        n = nums.size();
        
        for (i = n - 2; i >= 0; i--)
            if (nums[i] < nums[i + 1])
                break;
        
        if (i < 0)
            return false;

        for (j = n - 1; j > i; j--)
            if (nums[i] < nums[j])
                break;
        
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
        
        return true;
    }
};