/*
Problem Statement: https://leetcode.com/problems/task-scheduler/
Time: O(n)
Space: O(1)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	int leastInterval(vector<char>& tasks, int n) {
		int idle, max_f = 0;
		unordered_map<char, int> freq;
		
		for (char& t: tasks)
			max_f = max(++freq[t], max_f);
		idle = (n + 1) * (max_f - 1);
		
		for (auto& [t, f]: freq)
			idle -= min(f, max_f - 1);
		
		return tasks.size() + max(0, idle);
	}
};