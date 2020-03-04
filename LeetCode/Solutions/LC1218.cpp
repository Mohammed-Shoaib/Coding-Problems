/*
Problem Statement: https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/
*/

class Solution {
public:
    int longestSubsequence(vector<int> &arr, int difference) {
		int max_len = 0;
		unordered_map<int, int> map;

		for (int i = 0; i < arr.size(); i++) {
			map[arr[i]] = map[arr[i] - difference] + 1;
			max_len = max(map[arr[i]], max_len);
		}
		
		return max_len;
    }
};