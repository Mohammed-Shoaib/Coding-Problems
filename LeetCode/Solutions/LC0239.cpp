/*
Problem Statement: https://leetcode.com/problems/sliding-window-maximum/
Time: O(n)
Space: O(n + k)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		deque<int> d;
		vector<int> res;
		
		for (int i = 0; i < nums.size(); i++) {
			while(!d.empty() && nums[d.back()] < nums[i])
				d.pop_back();
			d.push_back(i);
			if (d.front() == i - k)
				d.pop_front();
			if (i >= k - 1)
				res.push_back(nums[d.front()]);
		}
		
		return res;
	}
};