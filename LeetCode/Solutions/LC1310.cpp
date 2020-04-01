/*
Problem Statement: https://leetcode.com/problems/xor-queries-of-a-subarray/
*/

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector< vector<int> >& queries) {
        int n = arr.size();
        vector<int> res, prefix(n + 1);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = arr[i] ^ prefix[i];
        for (vector<int>& q: queries)
            res.push_back(prefix[q[0]] ^ prefix[q[1] + 1]);
        return res;
    }
};