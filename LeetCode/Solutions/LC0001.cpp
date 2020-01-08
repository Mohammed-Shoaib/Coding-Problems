/*
Problem Statement: https://leetcode.com/problems/two-sum/
*/

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
    	int i;
    	unordered_map<int, int> map;
    	for (i = 0; i < nums.size(); i++) {
    		if (map.find(target - nums[i]) != map.end())
    			break;
    		map[nums[i]] = i;
    	}
    	return {map[target - nums[i]], i};
    }
};