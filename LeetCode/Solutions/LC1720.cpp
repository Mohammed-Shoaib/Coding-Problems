/*
Problem Statement: https://leetcode.com/problems/decode-xored-array/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> decode(vector<int>& encoded, int first) {
		int n = encoded.size() + 1;
		vector<int> arr(n);
		
		arr[0] = first;
		for (int i = 1; i < n; i++)
			arr[i] = encoded[i - 1] ^ arr[i - 1];
		
		return arr;
	}
};