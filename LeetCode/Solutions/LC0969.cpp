/*
Problem Statement: https://leetcode.com/problems/pancake-sorting/
Time: O(n²)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> pancakeSort(vector<int>& A) {
		int n = A.size();
		vector<int> res;
		for (int i = 0; i < n; i++) {
			int k = 1 + distance(A.begin(), max_element(A.begin(), A.begin() + n - i));
			reverse(A.begin(), A.begin() + k);
			reverse(A.begin(), A.begin() + n - i);
			res.push_back(k);
			res.push_back(n - i);
		}
		return res;
	}
};