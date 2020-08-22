/*
Problem Statement: https://leetcode.com/problems/last-stone-weight/
Time: O(n • log n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int lastStoneWeight(vector<int>& stones) {
		int x, y;
		priority_queue<int> pq(stones.begin(), stones.end());
		while (pq.size() > 1) {
			y = pq.top(), pq.pop();
			x = pq.top(), pq.pop();
			if (x != y)
				pq.push(y - x);
		}
		return pq.empty() ? 0 : pq.top();
	}
};