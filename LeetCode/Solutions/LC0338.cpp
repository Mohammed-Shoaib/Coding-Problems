/*
Problem Statement: https://leetcode.com/problems/counting-bits/
*/

class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> cnt(num + 1);
		for (int i = 1; i <= num; i++)
			cnt[i] = cnt[i >> 1] + (i & 1);
		return cnt;
	}
};