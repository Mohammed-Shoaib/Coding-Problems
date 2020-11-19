/*
Problem Statement: https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/
*/

class Solution {
public:
	int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
		int mod, max_h, max_w;
		mod = 1e9 + 7;
		max_h = max_w = 0;
		
		// preprocess
		verticalCuts.push_back(0);
		verticalCuts.push_back(w);
		horizontalCuts.push_back(0);
		horizontalCuts.push_back(h);

		// sort cuts
		sort(verticalCuts.begin(), verticalCuts.end());
		sort(horizontalCuts.begin(), horizontalCuts.end());

		// get maximum gap
		for (int i = 1; i < verticalCuts.size(); i++)
			max_w = max(verticalCuts[i] - verticalCuts[i - 1], max_w);
		for (int i = 1; i < horizontalCuts.size(); i++)
			max_h = max(horizontalCuts[i] - horizontalCuts[i - 1], max_h);
		
		return ((long long) max_w * max_h) % mod;
	}
};