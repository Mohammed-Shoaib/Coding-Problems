/*
Problem Statement: https://leetcode.com/problems/partition-labels/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> partitionLabels(string S) {
		int n, beg, end;
		n = S.length();
		beg = end = 0;
		vector<int> lengths, last(26);
		
		for (int i = 0; i < n; i++)
			last[S[i] - 'a'] = i;
		
		for (int i = 0; i < n; i++) {
			end = max(last[S[i] - 'a'], end);
			if (i == end) {
				lengths.push_back(end - beg + 1);
				beg = end + 1;
			}
		}
		
		return lengths;
	}
};