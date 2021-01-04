/*
Problem Statement: https://leetcode.com/problems/play-with-chips/
*/

class Solution {
public:
	int minCostToMoveChips(vector<int> &chips) {
		int odd, even;
		odd = even = 0;
		for (auto chip: chips)
			(chip & 1) ? odd++ : even++;
		return min(odd, even);
	}
};