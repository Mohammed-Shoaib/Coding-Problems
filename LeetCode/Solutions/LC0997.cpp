/*
Problem Statement: https://leetcode.com/problems/find-the-town-judge/
Time: O(M + N)
Space: O(N)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int findJudge(int N, vector<vector<int>>& trust) {
		int M = trust.size();
		vector<int> deg(N + 1);
		for (vector<int>& p: trust) {
			deg[p[0]]--;
			deg[p[1]]++;
		}
		for (int i = 1; i <= N; i++)
			if (deg[i] == N - 1)
				return i;
		return -1;
	}
};