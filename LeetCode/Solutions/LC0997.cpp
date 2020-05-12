/*
Problem Statement: https://leetcode.com/problems/find-the-town-judge/
*/

class Solution {
public:
	int findJudge(int N, vector<vector<int>>& trust) {
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