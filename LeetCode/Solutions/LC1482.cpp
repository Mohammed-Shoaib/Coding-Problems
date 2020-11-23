/*
Problem Statement: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
*/

class Solution {
public:
	int minDays(vector<int>& bloomDay, int m, int k) {
		int low, mid, high, n = bloomDay.size();
		
		if ((long long) m * k > n)
			return -1;
		
		// helper function
		auto good = [&](int day) -> bool {
			int len = 0, need = m;
			for (int& x: bloomDay) {
				if (x <= day)
					len++;
				else
					len = 0;
				if (len == k) {
					len = 0;
					need--;
				}
				if (need == 0)
					return true;
			}
			return false;
		};
		
		auto it = minmax_element(bloomDay.begin(), bloomDay.end());
		low = *it.first;
		high = *it.second;

		// binary search
		while (low < high) {
			mid = (low + high) / 2;
			if (good(mid))
				high = mid;
			else
				low = mid + 1;
		}

		return high;
	}
};