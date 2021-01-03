/*
Problem Statement: https://leetcode.com/problems/minimum-absolute-difference/
*/

class Solution {
public:
	vector< vector<int> > minimumAbsDifference(vector<int> &arr) {
		int min_diff = numeric_limits<int>::max();
		vector< vector<int> > pairs;
		sort(arr.begin(), arr.end());

		for (int i = 1; i < arr.size(); i++)
			min_diff = min(arr[i] - arr[i - 1], min_diff);

		for (int i = 1; i < arr.size(); i++)
			if (arr[i] - arr[i - 1] == min_diff)
				pairs.push_back({arr[i - 1], arr[i]});

		return pairs;
	}
};