/*
Problem Statement: https://leetcode.com/problems/count-number-of-nice-subarrays/
*/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
		int nice, cnt;
		vector<int> gaps;
		nice = 0;
		cnt = 1;
		
		for (int i = 0; i < nums.size(); i++, cnt++)
			if (nums[i] & 1) {
				gaps.push_back(cnt);
				cnt = 0;
			}
		gaps.push_back(cnt);

		for (int i = 0; i + k < gaps.size(); i++)
			nice += gaps[i] * gaps[i + k];

		return nice;
    }
};