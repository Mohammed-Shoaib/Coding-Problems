/*
Problem Statement: https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/
Time: O(m + n)
Space: O(m + n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int maxArea(int h, int w, vector<int> horizontalCuts, vector<int> verticalCuts) {		
		// preprocess
		verticalCuts.push_back(0);
		verticalCuts.push_back(w);
		horizontalCuts.push_back(0);
		horizontalCuts.push_back(h);
		
		int mod, max_h, max_w, m, n;
		mod = 1e9 + 7;
		max_h = max_w = 0;
		m = verticalCuts.size();
		n = horizontalCuts.size();
		
		// sort cuts
		sort(verticalCuts.begin(), verticalCuts.end());
		sort(horizontalCuts.begin(), horizontalCuts.end());
		
		// get maximum gap
		for (int i = 1; i < m; i++)
			max_w = max(verticalCuts[i] - verticalCuts[i - 1], max_w);
		for (int i = 1; i < n; i++)
			max_h = max(horizontalCuts[i] - horizontalCuts[i - 1], max_h);
		
		return ((int64_t) max_w * max_h) % mod;
	}
};