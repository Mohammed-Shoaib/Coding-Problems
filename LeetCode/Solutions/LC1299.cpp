/*
Problem Statement: https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/
*/

class Solution {
public:
	vector<int> replaceElements(vector<int>& arr) {
		int max_v = -1;
		for (int i = arr.size() - 1; i >= 0; i--)
			max_v = max(exchange(arr[i], max_v), max_v);
		return arr;
	}
};