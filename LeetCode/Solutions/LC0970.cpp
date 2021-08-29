/*
Problem Statement: https://leetcode.com/problems/powerful-integers/
Time: O(log²(bound))
Space: O(log²(bound))
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> powerfulIntegers(int x, int y, int bound) {
		unordered_set<int> seen;
		
		for (int p = 1; p < bound; p *= x) {
			for (int q = 1; p + q <= bound; q *= y) {
				seen.insert(p + q);
				if (y == 1)
					break;
			}
			if (x == 1)
				break;
		}
		
		return vector<int>(seen.begin(), seen.end());
	}
};