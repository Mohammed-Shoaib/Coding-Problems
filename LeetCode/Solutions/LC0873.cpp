/*
Problem Statement: https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/
Time: O(n³) = O(n² • log (max(arr)))
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int lenLongestFibSubseq(vector<int>& arr) {
		int max_len = 0, n = arr.size();
		unordered_set<int> seen(arr.begin(), arr.end());
		
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++) {
				int f0 = arr[i], f1 = arr[j], len = 2;
				while (seen.count(f0 + f1)) {
					++len;
					f0 = exchange(f1, f0 + f1);
				}
				if (len >= 3)
					max_len = max(len, max_len);
			}
		
		return max_len;
	}
};