/*
Problem Statement: https://leetcode.com/problems/container-with-most-water/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int maxArea(vector<int>& height) {
		int max_area, beg, end;
		max_area = beg = 0;
		end = height.size() - 1;
		
		// two pointer
		while (beg < end) {
			int area = (end - beg) * min(height[beg], height[end]);
			max_area = max(area, max_area);
			if (height[beg] < height[end])
				beg++;
			else
				end--;
		}
		
		return max_area;
	}
};