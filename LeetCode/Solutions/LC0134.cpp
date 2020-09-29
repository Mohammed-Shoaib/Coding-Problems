/*
Problem Statement: https://leetcode.com/problems/gas-station/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int n, pos, sum, tank;
		n = gas.size();
		pos = sum = tank = 0;
		
		for (int i = 0; i < n; i++) {
			tank += gas[i] - cost[i];
			if (tank < 0) {
				pos = i + 1;
				sum += exchange(tank, 0);
			}
		}
		sum += tank;
		
		return (sum >= 0) ? pos : -1;
	}
};