/*
Problem Statement: https://leetcode.com/problems/subsets/
*/

class Solution {
public:
    vector< vector<int> > subsets(vector<int>& nums) {
        int n, size;
        n = nums.size();
        size = 1 << n;
        vector< vector<int> > sets(size);

        for (int i = 0; i < size; i++)
            for (int j = 0; j < n; j++)
                if (i & (1 << j))
                    sets[i].push_back(nums[j]);
        
        return sets;
    }
};