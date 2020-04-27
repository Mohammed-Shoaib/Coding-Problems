/*
Problem Statement: https://leetcode.com/problems/contiguous-array/
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int max_l, sum;
        unordered_map<int, int> m;
        max_l = sum = 0;
        m[sum] = -1;

        for (int i = 0; i < nums.size(); i++) {
            sum += (nums[i] == 0) ? -1 : 1;
            if (m.count(sum))
                max_l = max(i - m[sum], max_l);
            else
                m[sum] = i;
        }
        
        return max_l;
    }
};