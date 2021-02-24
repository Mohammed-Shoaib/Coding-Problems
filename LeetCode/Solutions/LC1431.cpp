/*
Problem Statement: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
Time: O(n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
		int max_candies, n = candies.size();
		max_candies = *max_element(candies.begin(), candies.end());
		vector<bool> kids(n);
		
		for (int i = 0; i < n; i++)
			kids[i] = candies[i] + extraCandies >= max_candies;
		
		return kids;
	}
};