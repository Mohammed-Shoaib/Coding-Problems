/*
Problem Statement: https://leetcode.com/problems/shuffle-an-array/
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib

|----------------|-------|-------|
| Operations     | Time  | Space |
|----------------|-------|-------|
| Solution(nums) | O(n)  | O(n)  |
| reset()        | O(n)  | O(n)  |
| shuffle()      | O(n)  | O(n)  |
|----------------|-------|-------|
*/

class Solution {
private:
	mt19937 gen;
	vector<int> org, nums;
public:
	Solution(vector<int>& nums): org(nums), nums(nums), gen(random_device{}()) {}
	
	vector<int> reset() {
		return org;
	}
	
	vector<int> shuffle() {
		int n = nums.size();
		
		// fisher–yates shuffle, durstenfeld's version
		for (int i = 0; i < n; i++) {
			int pos = uniform_int_distribution<int>{i, n - 1}(gen);
			swap(nums[i], nums[pos]);
		}
		
		return nums;
	}
};