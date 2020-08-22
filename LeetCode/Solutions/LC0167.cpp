/*
Problem Statement: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
*/

class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int low, high, sum;
		low = 0;
		high = numbers.size() - 1;
		
		while (low < high) {
			sum = numbers[low] + numbers[high];
			if (sum == target)
				return {low + 1, high + 1};
			else if (sum < target)
				low++;
			else
				high--;
		}
		
		return {0, 0};
	}
};