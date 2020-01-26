/*
Problem Statement: https://leetcode.com/problems/gray-code/
*/

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> gray;
        for (int i = 0; i < 1 << n; i++)
            gray.push_back(i ^ (i >> 1));
        return gray;
    }
};