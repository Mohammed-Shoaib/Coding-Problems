/*
Problem Statement: https://leetcode.com/problems/word-ladder-ii/
*/

class Solution {
public:
	vector< vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList) {
		string s1, s2;
		vector<string> path, added;
		queue< vector<string> > q;
		vector< vector<string> > paths;
		unordered_set<string> words(wordList.begin(), wordList.end());
		q.push({beginWord});
		
		while (!q.empty()) {
			int size = q.size();
			added.clear();
			while (size--) {
				path = q.front();
				q.pop();
				if (path.back() == endWord) {
					paths.push_back(path);
					continue;
				}
				s1 = s2 = path.back();
				for (int i = 0; i < s1.length(); i++)
					for (char c = 'a'; c <= 'z'; c++) {
						s2[i] = c;
						if (words.count(s2)) {
							path.push_back(s2);
							q.push(path);
							path.pop_back();
							added.push_back(s2);
						}
						s2[i] = s1[i];
					}
			}
			for (string& s: added)
				words.erase(s);
		}
		
		return paths;
	}
};