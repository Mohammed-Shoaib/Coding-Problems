/*
Problem Statement: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
*/

class Solution {
public:
	vector<int> sortByBits(vector<int> arr) {
		sort(arr.begin(), arr.end(), [](int l, int r) {
			int cnt_l, cnt_r;
			cnt_l = __builtin_popcount(l);
			cnt_r = __builtin_popcount(r);
			if (cnt_l == cnt_r)
				return l < r;
			else
				return cnt_l < cnt_r;
		});
		return arr;
	}
};