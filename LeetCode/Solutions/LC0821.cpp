/*
Problem Statement: https://leetcode.com/problems/shortest-distance-to-a-character/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> shortestToChar(string S, char C) {
		int pos = S.find(C), n = S.length();
		vector<int> dist(n, numeric_limits<int>::max());
		
		for (int i = pos; i < n; i++) {
			if (S[i] == C)
				pos = i;
			dist[i] = i - pos;
		}
		
		for (int i = pos; i >= 0; i--) {
			if (S[i] == C)
				pos = i;
			dist[i] = min(pos - i, dist[i]);
		}
		
		return dist;
	}
};