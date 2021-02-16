/*
Problem Statement: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
Time: O(m • log max(m, n))
Space: O(m)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
		int m = mat.size(), n = mat[0].size();
		vector<int> rows(k);
		priority_queue<pair<int, int>> pq;
		
		for (int i = 0; i < m; i++) {
			int soldiers = distance(mat[i].begin(), 
				upper_bound(mat[i].begin(), mat[i].end(), 1, greater<int>()));
			pq.push({soldiers, i});
			if (pq.size() > k)
				pq.pop();
		}
		
		while (!pq.empty()) {
			rows[--k] = move(pq.top().second);
			pq.pop();
		}
		
		return rows;
	}
};