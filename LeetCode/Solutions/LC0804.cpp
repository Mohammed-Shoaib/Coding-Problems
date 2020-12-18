/*
Problem Statement: https://leetcode.com/problems/unique-morse-code-words/
Time: O(n • len)
Space: O(n • len)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class Solution {
private:
	vector<string> mp;
	string morse_code(string& s) {
		string code;
		for (char& c: s)
			code += mp[c - 'a'];
		return code;
	}
	
public:
	Solution(): mp{".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."} {}
	
	int uniqueMorseRepresentations(vector<string>& words) {
		unordered_set<string> seen;
		for (string& word: words)
			seen.insert(morse_code(word));
		return seen.size();
	}
};