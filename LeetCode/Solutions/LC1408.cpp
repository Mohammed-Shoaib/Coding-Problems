/*
Problem Statement: https://leetcode.com/problems/string-matching-in-an-array/
*/

class Solution {
public:
	vector<string> stringMatching(vector<string>& words) {
		vector<string> subs;
		for (string& w1: words)
			for (string& w2: words)
				if (w1 != w2 && w2.find(w1) != string::npos) {	// words are unique
					subs.push_back(w1);
					break;
				}
		return subs;
	}
};