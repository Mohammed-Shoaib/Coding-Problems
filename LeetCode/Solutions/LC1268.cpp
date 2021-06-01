/*
Problem Statement: https://leetcode.com/problems/search-suggestions-system/
Time: O((m + n) • max_len)
Space: O(m • n • max_len)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

struct TrieNode {
	int words;
	vector<TrieNode*> children;
	
	TrieNode() : words(0), children(26) {}
};

struct Trie {
	TrieNode* root;
	
	Trie(vector<string>& words) : root(new TrieNode()) {
		for (string& word: words)
			insert(word);
	}
	
	void insert(string& word) {
		TrieNode* node = root;
		for (char& c: word) {
			if (!node->children[c - 'a'])
				node->children[c - 'a'] = new TrieNode();
			node = node->children[c - 'a'];
		}
		node->words++;
	}
	
	TrieNode* search(char c, TrieNode* node) {
		if (!node || !node->children[c - 'a'])
			return nullptr;
		return node->children[c - 'a'];
	}
	
	vector<string> get_suggestions(string path, TrieNode* node) {
		vector<string> res;
		stack<TrieNode*> st;
		
		// helper function
		function<void(TrieNode*)> dfs = [&](TrieNode* node) {
			if (res.size() == 3)
				return;
			else if (node->words)
				res.push_back(path);
			for (char c = 'a'; c <= 'z'; c++)
				if (node->children[c - 'a']) {
					path += c;
					dfs(node->children[c - 'a']);
					path.pop_back();
				}
		};
		if (node)
			dfs(node);
		
		return res;
	}
};

class Solution {
public:
	vector<vector<string>> suggestedProducts(vector<string>& products, string& searchWord) {
		int m = products.size(), n = searchWord.length();
		string word;
		Trie trie(products);
		TrieNode* node = trie.root;
		vector<vector<string>> suggestions(n);
		
		for (int i = 0; i < n; i++) {
			word += searchWord[i];
			node = trie.search(searchWord[i], node);
			suggestions[i] = trie.get_suggestions(word, node);
		}
		
		return suggestions;
	}
};