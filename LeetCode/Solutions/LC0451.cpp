/*
Problem Statement: https://leetcode.com/problems/sort-characters-by-frequency/
*/

class Solution {
public:
	string frequencySort(string s) {
		string res;
		unordered_map<char, int> freq;
		priority_queue<pair<int, char>> pq;

		for (char& c: s)
			freq[c]++;
		
		for (auto it: freq)
			pq.push({it.second, it.first});
		
		while (!pq.empty()) {
			auto p = pq.top();
			pq.pop();
			res += string(p.first, p.second);
		}
		
		return res;
	}
};