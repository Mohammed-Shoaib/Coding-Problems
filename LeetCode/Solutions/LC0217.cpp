/*
Problem Statement: https://leetcode.com/problems/contains-duplicate/
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> seen(nums.begin(), nums.end());
		return seen.size() != nums.size();
    }
};