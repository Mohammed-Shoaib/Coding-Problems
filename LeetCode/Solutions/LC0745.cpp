/*
Problem Statement: https://leetcode.com/problems/prefix-and-suffix-search/
Space: O(words • len)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib

Paired Trie Implementation
|-------------------------|----------------------------------|----------------|
| Operations              | Time                             | Space          |
|-------------------------|----------------------------------|----------------|
| WordFilter(words)       | O(words • len)                   | O(1)           |
| insert(words)           | O(words • len)                   | O(1)           |
| f(prefix, suffix)       | O(prefix + suffix + words • len) | O(words • len) |
|-------------------------|----------------------------------|----------------|
*/

class TrieNode {
public:
	int pos = -1;
	map<pair<char, char>, TrieNode*> children;
};

class WordFilter {
private:
	TrieNode* root;
	
	void insert(vector<string>& words) {
		int n = words.size();
		
		for (int i = 0; i < n; i++) {
			int m = words[i].length();
			TrieNode* node = root;
			pair<char, char> k;
			
			for (int j = 0; j < m; j++) {
				k = {words[i][j], words[i][m - j - 1]};
				if (!node->children.count(k))
					node->children[k] = new TrieNode();
				node = node->children[k];
			}
			
			node->pos = max(i, node->pos);			
		}
	}

public:
	WordFilter(vector<string>& words): root(new TrieNode()) {
		insert(words);
	}
	
	int f(string prefix, string suffix) {
		int max_pos = -1, m = min(prefix.length(), suffix.length());
		string extra;
		queue<TrieNode*> q;
		pair<char, char> k;
		TrieNode* node = root;
		reverse(suffix.begin(), suffix.end());
		
		// check for prefix and suffix
		for (int i = 0; i < m; i++) {
			k = {prefix[i], suffix[i]};
			if (!node->children.count(k))
				return -1;
			node = node->children[k];
		}
		
		q.push(node);
		if (prefix.length() > m)
			extra = prefix.substr(m);
		else if (suffix.length() > m)
			extra = suffix.substr(m);
		
		// process the extra prefix or suffix
		for (int i = 0; i < extra.length(); i++) {
			int size = q.size();
			while (size--) {
				node = q.front();
				q.pop();
				for (auto& [k, u]: node->children) {
					char c = (prefix.length() > m) ? k.first : k.second;
					if (c == extra[i])
						q.push(u);
				}
			}
		}
		
		// BFS
		while (!q.empty()) {
			node = q.front();
			q.pop();
			max_pos = max(node->pos, max_pos);
			for (auto& [k, u]: node->children)
				q.push(u);
		}
		
		return max_pos;
	}
};