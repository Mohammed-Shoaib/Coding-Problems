/*
Problem Statement: https://leetcode.com/problems/contains-duplicate-iii/
Time: O(n)
Space: O(k)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		int n = nums.size();
		unordered_map<long long, long long> buckets;
		
		// helper function
		auto search = [&](int pos, long long bucket) {
			auto it = buckets.find(bucket);
			return (it != buckets.end() && abs(nums[pos] - it->second) <= t);
		};
		auto get_bucket = [&](int i) {
			return nums[i] / (t + (t == 0));
		};
		
		for (int i = 0; i < n; i++) {
			long long bucket = get_bucket(i);
			if (search(i, bucket) || search(i, bucket - 1) || search(i, bucket + 1))
				return true;
			buckets[bucket] = nums[i];
			if (i >= k)
				buckets.erase(get_bucket(i - k));
		}
		
		return false;
	}
};