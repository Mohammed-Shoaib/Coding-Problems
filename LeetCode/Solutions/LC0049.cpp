/*
Problem Statement: https://leetcode.com/problems/group-anagrams/
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> groups;
        unordered_map<string, vector<string>> m;
		for (string& s: strs) {
			string copy(s);
			sort(copy.begin(), copy.end());
			m[copy].push_back(s);
		}
		for (auto& [k, v]: m)
			groups.push_back(v);
		return groups;
    }
};