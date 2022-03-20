/*
Problem Statement: https://leetcode.com/problems/construct-the-rectangle/
Time: O(sqrt(n))
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> constructRectangle(int area) {
		int W = sqrt(area);
		
		while (area % W)
			W--;
		
		return {area / W, W};
	}
};