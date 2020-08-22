/*
Problem Statement: https://leetcode.com/problems/majority-element-ii/
*/

class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		// generalized solution for n / k
		int k = 3;
		vector<int> m;
		unordered_map<int, int> counters;
		
		// maintain k counters
		for (auto num: nums) {
			if (counters.size() < k - 1 || counters.count(num))
				counters[num]++;
			else {
				auto it = counters.begin();
				while (it != counters.end()) {
					it->second--;
					if (it->second == 0)
						it = counters.erase(it);
					else
						it++;
				}
			}
		}
		
		// check if element occurs more than n / k times
		for (auto it: counters)
			if (count(nums.begin(), nums.end(), it.first) > nums.size() / k)
				m.push_back(it.first);
		
		return m;
	}
};