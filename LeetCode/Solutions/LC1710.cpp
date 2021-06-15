/*
Problem Statement: https://leetcode.com/problems/maximum-units-on-a-truck/
Time: O(n • log n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
		int units = 0;
		
		sort(boxTypes.begin(), boxTypes.end(), [&](auto& l, auto& r) {
			return l[1] > r[1];
		});
		
		for (vector<int>& box: boxTypes) {
			units += min(truckSize, box[0]) * box[1];
			truckSize -= min(truckSize, box[0]);
		}
		
		return units;	
	}
};