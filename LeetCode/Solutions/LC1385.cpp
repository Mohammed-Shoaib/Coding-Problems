/*
Problem Statement: https://leetcode.com/problems/find-the-distance-value-between-two-arrays/
*/

class Solution {
public:
	int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
		int cnt = 0;
		for (int i = 0; i < arr1.size(); i++) {
			bool ok = true;
			for (int j = 0; j < arr2.size(); j++)
				ok &= abs(arr1[i] - arr2[j]) > d;
			cnt += ok;
		}
		return cnt;
	}
};