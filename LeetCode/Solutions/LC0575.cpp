/*
Problem Statement: https://leetcode.com/problems/distribute-candies/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int distributeCandies(vector<int>& candies) {
		unordered_set<int> seen(candies.begin(), candies.end());
		return min(seen.size(), candies.size() / 2);
	}
};