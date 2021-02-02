/*
Problem Statement: https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/
*/

class Solution {
public:
	vector<int> sumZero(int n) {
		vector<int> arr(n);
		for (int i = 0; i < n; i++)
			arr[i] = (i << 1) - n + 1;
		return arr;
	}
};