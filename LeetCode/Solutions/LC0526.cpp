/*
Problem Statement: https://leetcode.com/problems/beautiful-arrangement/
Time: O(n! + n • sqrt(n))
Space: O(n • n¹ᐟ³ = n⁴ᐟ³)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int countArrangement(int n) {
		int cnt = 0;
		vector<bool> used(n + 1);
		vector<vector<int>> adj(n + 1);
		
		// helper function
		function<void(int)> state = [&](int pos) {
			if (pos == n + 1) {
				cnt++;
				return;
			}
			
			for (int& u: adj[pos])
				if (!used[u]) {
					used[u] = true;
					state(pos + 1);
					used[u] = false;
				}
		};
		
		// create adjacency list by using divisors of i
		adj[1].push_back(1);
		for (int i = 2; i <= n; i++)
			for (int j = 1; j * j <= i; j++) {
				if (i % j != 0)
					continue;
				adj[i].push_back(j);
				adj[j].push_back(i);
				if (j * j < i) {
					adj[i].push_back(i / j);
					if (j > 1)
						adj[i / j].push_back(i);
				}
			}
		state(1);
		
		return cnt;
	}
};