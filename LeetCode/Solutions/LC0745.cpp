/*
Problem Statement: https://leetcode.com/problems/prefix-and-suffix-search/
Space: O(words • len)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib

|-------------------------|--------------------------|--------|
| Operations              | Time                     | Space  |
|-------------------------|--------------------------|--------|
| WordFilter(words)       | O(words • len)           | O(1)   |
| ends_with(word, suffix) | O(suffix)                | O(1)   |
| insert(words)           | O(words • len)           | O(1)   |
| f(prefix, suffix)       | O(prefix + suffix • len) | O(len) |
|-------------------------|--------------------------|--------|
*/

class TrieNode {
public:
	int pos = 0;
	unordered_map<char, TrieNode*> children;
};

class WordFilter {
private:
	TrieNode* root;
	
	bool ends_with(string& word, string& suffix) {
		if (suffix.length() > word.length())
			return false;
		else
			return equal(suffix.rbegin(), suffix.rend(), word.rbegin());
	}
	
	void insert(vector<string>& words) {
		int n = words.size();
		
		for (int i = 0; i < n; i++) {
			TrieNode* node = root;
			for (char& c: words[i]) {
				if (!node->children.count(c))
					node->children[c] = new TrieNode();
				node = node->children[c];
			}
			node->pos = max(i, node->pos);
		}
	}

public:
	WordFilter(vector<string>& words): root(new TrieNode()) {
		insert(words);
	}
	
	int f(string prefix, string suffix) {
		int max_pos = -1;
		string s = prefix;
		TrieNode* node = root;
		
		// check for prefix
		for (char& c: prefix) {
			if (!node->children.count(c))
				return -1;
			node = node->children[c];
		}
		
		// helper function
		function<void(TrieNode*)> dfs = [&](TrieNode* node) {
			// check for suffix
			if (ends_with(s, suffix))
				max_pos = max(node->pos, max_pos);
			
			for (auto& [c, child]: node->children) {
				s += c;
				dfs(child);
				s.pop_back();
			}
		};
		dfs(node);
		
		return max_pos;
	}
};