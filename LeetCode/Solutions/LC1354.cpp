/*
Problem Statement: https://leetcode.com/problems/construct-target-array-with-multiple-sums/
Time: O(n • log n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool isPossible(vector<int>& target) {
		int64_t sum = 0;
		priority_queue<int> pq;
		
		for (int& x: target) {
			sum += x;
			if (x > 1)
				pq.push(x);
		}
		
		while (!pq.empty()) {
			int big = pq.top();
			pq.pop();
			sum -= big;
			if (sum == 0 || big <= sum)
				return false;
			big %= sum;
			sum += big;
			if (big > 1)
				pq.push(big);
		}
		
		return true;
	}
};