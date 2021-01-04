/*
Problem Statement: https://leetcode.com/problems/unique-number-of-occurrences/
*/

class Solution {
public:
	bool uniqueOccurrences(vector<int> &arr) {
		map<int, int> freq;
		vector<int> count;
		for (int i = 0; i < arr.size(); i++)
			freq[arr[i]]++;
		for (auto f: freq)
			count.push_back(f.second);
		unordered_set<int> set(count.begin(), count.end());
		return count.size() == set.size();
	}
};