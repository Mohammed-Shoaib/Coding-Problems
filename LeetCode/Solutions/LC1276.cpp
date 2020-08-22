/*
Problem Statement: https://leetcode.com/problems/number-of-burgers-with-no-waste-of-ingredients/
Time: O(1)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
		/*
		4x + 2y = tomato;
		x + y = cheese;
		x = (tomato - 2 * cheese) / 2;
		y = cheese - x;
		*/
		int x, y, sub;
		sub = (tomatoSlices - 2 * cheeseSlices);
		x = sub / 2;
		y = cheeseSlices - x;
		if (sub < 0 || (sub & 1) || y < 0)
			return {};
		else
			return {x, y};
	}
};