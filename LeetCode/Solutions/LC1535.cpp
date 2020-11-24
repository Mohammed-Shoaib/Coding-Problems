/*
Problem Statement: https://leetcode.com/problems/find-the-winner-of-an-array-game/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int getWinner(vector<int>& arr, int k) {
		int ele = arr[0], wins = 0;
		for (int i = 1; i < arr.size(); i++) {
			if (ele < arr[i]) {
				wins = 0;
				ele = arr[i];
			}
			if (++wins == k)
				break;
		}
		return ele;
	}
};