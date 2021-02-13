/*
Problem Statement: https://leetcode.com/problems/check-if-n-and-its-double-exist/
*/

class Solution {
public:
	bool checkIfExist(vector<int> arr) {
		unordered_set<int> seen;
		for (int& a: arr) {
			if (seen.count(2 * a) || a % 2 == 0 && seen.count(a / 2))
				return true;
			seen.insert(a);
		}
		return false;
	}
};