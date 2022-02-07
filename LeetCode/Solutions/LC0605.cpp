/*
Problem Statement: https://leetcode.com/problems/can-place-flowers/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		bool prev = false;
		int m = flowerbed.size();
		
		for (int i = 0; i < m; i++) {
			bool next = (i + 1 < m) ? flowerbed[i + 1] : false;
			
			if (!prev && !next && !flowerbed[i]) {
				n--;
				prev = true;
			}
			else
				prev = flowerbed[i];
			
			if (n <= 0)
				return true;
		}
		
		return false;
	}
};