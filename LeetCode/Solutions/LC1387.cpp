/*
Problem Statement: https://leetcode.com/problems/sort-integers-by-the-power-value/
*/

class Solution {
public:
	int power(int x) {
		int steps = 0;
		while (x != 1) {
			if (x & 1)
				x = 3 * x + 1;
			else
				x /= 2;
			steps++;
		}
		return steps;
	}

	int getKth(int lo, int hi, int k) {
		vector<pair<int, int>> arr;
		for (int i = lo; i <= hi; i++)
			arr.push_back({power(i), i});
		sort(arr.begin(), arr.end());
		return arr[k - 1].second;
	}
};