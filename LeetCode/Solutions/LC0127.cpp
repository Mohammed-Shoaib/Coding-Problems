/*
Problem Statement: https://leetcode.com/problems/word-ladder/
*/

class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		int len;
		string s;
		queue< pair<string, int> > q;
		unordered_set<string> words(wordList.begin(), wordList.end());
		q.push({beginWord, 1});
		
		while (!q.empty()) {
			tie(beginWord, len) = q.front();
			q.pop();
			if (beginWord == endWord)
				return len;
			s = beginWord;
			for (int i = 0; i < s.length(); i++)
				for (char c = 'a'; c <= 'z'; c++) {
					s[i] = c;
					if (words.count(s)) {
						words.erase(s);
						q.push({s, len + 1});
					}
					s[i] = beginWord[i];
				}
		}
		
		return 0;
	}
};