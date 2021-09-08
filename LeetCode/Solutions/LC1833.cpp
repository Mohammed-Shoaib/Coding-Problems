/*
Problem Statement: https://leetcode.com/problems/maximum-ice-cream-bars/
Time: O(n • log n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int maxIceCream(vector<int>& costs, int coins) {
		priority_queue<int> pq;
		
		for (int& cost: costs) {
			if (!pq.empty() && coins < cost && cost < pq.top()) {
				coins += pq.top();
				pq.pop();
			}
			if (coins >= cost) {
				coins -= cost;
				pq.push(cost);
			}
		}
		
		return pq.size();
	}
};