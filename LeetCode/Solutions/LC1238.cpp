/*
Problem Statement: https://leetcode.com/problems/circular-permutation-in-binary-representation/
*/

class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> gray;
        for (int i = 0; i < 1 << n; i++)
            gray.push_back(start ^ i ^ (i >> 1));
        return gray;
    }
};