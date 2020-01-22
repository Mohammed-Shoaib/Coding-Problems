/*
Problem Statement: https://leetcode.com/problems/group-anagrams/
*/

class Solution {
public:
    vector< vector<string> > groupAnagrams(vector<string>& strs) {
		string s;
		vector< vector<string> > groups;
		unordered_map<string, vector<string> > m;

		for (string& word: strs) {
			s = word;
			sort(s.begin(), s.end());
			m[s].push_back(word);
		}
		
		for (auto it: m)
			groups.push_back(it.second);
		
		return groups;
    }
};