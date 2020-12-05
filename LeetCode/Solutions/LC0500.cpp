/*
Problem Statement: https://leetcode.com/problems/keyboard-row/
Time: O(n • len)
Space: O(n • len)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
public:
	vector<string> findWords(vector<string>& words) {
		vector<string> res;
		vector<unordered_set<char>> rows = {
			{ 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P' },
			{ 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L' },
			{ 'Z', 'X', 'C', 'V', 'B', 'N', 'M' }
		};
		
		for (auto& row: rows)
			for (string& word: words) {
				bool can_type = true;
				for (char& c: word)
					can_type &= row.count(toupper(c));
				if (can_type)
					res.push_back(word);
			}
		
		return res;
	}
};