/*
Problem Statement: https://leetcode.com/problems/buddy-strings/
Time: O(n)
Space: O(26)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool buddyStrings(string A, string B) {
		bool dup = false;
		int swaps = 0, n = A.length();
		vector<int> freq_a(26), freq_b(26);
		
		if (n != B.length())
			return false;
		
		for (int i = 0; i < n; i++) {
			freq_a[A[i] - 'a']++;
			dup |= freq_b[B[i] - 'a']++;
			swaps += (A[i] != B[i]);
		}
		
		return swaps ? (swaps == 2 && freq_a == freq_b) : dup;
	}
};