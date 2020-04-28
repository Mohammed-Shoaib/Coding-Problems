/*
Problem Statement: https://leetcode.com/problems/subarray-sum-equals-k/
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
		int cnt, sum;
		unordered_map<int, int> freq;
		freq[0]++;
		cnt = sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
			cnt += m[sum - k];
			m[sum]++;
		}
		return cnt;
    }
};