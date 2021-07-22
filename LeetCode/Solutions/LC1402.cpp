/*
Problem Statement: https://leetcode.com/problems/reducing-dishes/
Time: O(n • log n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int maxSatisfaction(vector<int> sat) {
		int n, sum, run_sum;
		n = sat.size();
		sum = run_sum = 0;
		sort(sat.rbegin(), sat.rend());
		for (int i = 0; i < n && run_sum + sat[i] > 0; i++) {
			run_sum += sat[i];
			sum += run_sum;
		}
		return sum;
	}
};