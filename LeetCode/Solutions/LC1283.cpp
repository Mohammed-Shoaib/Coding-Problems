/*
Problem Statement: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
*/

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
		int low, mid, high, sum;
		low = 1;
		high = *max_element(nums.begin(), nums.end());

		while (low < high) {
			mid = (low + high) / 2;
			sum = get_sum(nums, mid);

			if (sum > threshold)
				low = mid + 1;
			else
				high = mid;
		}

		return high;
    }

	int get_sum(vector<int>& nums, int d) {
		int sum = 0;
		for (int i = 0; i < nums.size(); i++)
			sum += (nums[i] + d - 1) / d;
		return sum;
	}
};