/*
Problem Statement: https://leetcode.com/problems/bulb-switcher-iii/
*/

class Solution {
public:
	int numTimesAllBlue(vector<int>& light) {
		int cnt, max_l;
		cnt = max_l = 0;
		for (int i = 1; i <= light.size(); i++) {
			max_l = max(light[i - 1], max_l);
			cnt += (i == max_l);
		}
		return cnt;
	}
};