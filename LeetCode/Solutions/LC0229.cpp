/*
Problem Statement: https://leetcode.com/problems/majority-element-ii/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		int n, m1, m2, cnt1, cnt2;
		vector<int> m;
		n = nums.size();
		cnt1 = cnt2 = 0;
		
		// Boyer–Moore majority vote
		for (int& x: nums) {
			if (m1 == x)
				cnt1++;
			else if (m2 == x)
				cnt2++;
			else if (cnt1 == 0) {
				m1 = x;
				cnt1++;
			} else if (cnt2 == 0) {
				m2 = x;
				cnt2++;
			} else {
				cnt1--;
				cnt2--;
			}
		}
		
		cnt1 = count(nums.begin(), nums.end(), m1);
		cnt2 = count(nums.begin(), nums.end(), m2);
		
		if (cnt1 > n / 3)
			m.push_back(m1);
		if (cnt2 > n / 3)
			m.push_back(m2);
		
		return m;
	}
};