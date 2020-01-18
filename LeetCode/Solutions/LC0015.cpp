/*
Problem Statement: https://leetcode.com/problems/3sum/
*/

class Solution {
public:
    vector< vector<int> > threeSum(vector<int> &nums) {
    	int low, high, sum;
    	vector< vector<int> > triplets;
    	sort(nums.begin(), nums.end());

    	for (int i = 0; i < (int) nums.size() - 2 && nums[i] <= 0; i++) {
    		if (i > 0 && nums[i] == nums[i - 1])
    			continue;
    		low = i + 1;
    		high = nums.size() - 1;
    		while (low < high) {
    			sum = nums[i] + nums[low] + nums[high];
    			if (sum == 0) {
    				triplets.push_back({nums[i], nums[low], nums[high]});
    				while (low < high && nums[low] == nums[low + 1])
    					low++;
    				while (low < high && nums[high] == nums[high - 1])
    					high--;
    				low++;
    				high--;
    			}
    			else if (sum < 0)
    				low++;
    			else
    				high--;
    		}
    	}

    	return triplets;
    }
};