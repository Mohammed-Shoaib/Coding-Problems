/*
Problem Statement: https://leetcode.com/problems/majority-element/
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int m, counter = 0;
        for (auto num: nums) {
            if (!counter)
                m = num;
            counter += (m == num) ? 1 : -1;
        }
        return m;
    }
};