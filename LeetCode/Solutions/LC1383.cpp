/*
Problem Statement: https://leetcode.com/problems/maximum-performance-of-a-team/
Time: O(n • (log n + log k))
Space: O(n + k)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
		int mod = 1e9 + 7;
		int64_t max_p, sum;
		max_p = sum = 0;
		vector<pair<int, int>> eng(n);
		priority_queue<int, vector<int>, greater<int>> pq;
		
		// sort by efficiency in decreasing order
		for (int i = 0; i < n; i++)
			eng[i] = {efficiency[i], speed[i]};
		sort(eng.rbegin(), eng.rend());
		
		// find max performance
		for (int i = 0; i < n; i++) {
			if (pq.size() == k) {
				sum -= pq.top();
				pq.pop();
			}
			sum += eng[i].second;
			pq.push(eng[i].second);
			max_p = max(eng[i].first * sum, max_p);
		}
		
		return max_p % mod;
	}
};