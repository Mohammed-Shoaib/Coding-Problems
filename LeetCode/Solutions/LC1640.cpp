/*
Problem Statement: https://leetcode.com/problems/check-array-formation-through-concatenation/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
		int n = arr.size();
		unordered_map<int, int> mp;
		
		for (int i = 0; i < pieces.size(); i++)
			mp[pieces[i][0]] = i;
		
		for (int i = 0; i < n; ) {
			vector<int>& piece = pieces[mp[arr[i]]];
			for (int j = 0; j < piece.size(); i++, j++)
				if (arr[i] != piece[j])
					return false;
		}
		
		return true;
	}
};