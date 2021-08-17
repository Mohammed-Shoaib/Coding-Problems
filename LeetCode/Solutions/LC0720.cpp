/*
Problem Statement: https://leetcode.com/problems/longest-word-in-dictionary/
Time: O(n • max_len)
Space: O(n • max_len)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

struct TrieNode {
	int words, len;
	unordered_map<char, TrieNode*> children;
	
	TrieNode(): words(0), len(0) {}
};

struct Trie {
	TrieNode* root;
	
	Trie(vector<string>& words): root(new TrieNode()) {
		for (string& word: words)
			insert(word);
	}
	
	void insert(string& s) {
		TrieNode* node = root;
		for (char& c: s) {
			if (!node->children.count(c))
				node->children[c] = new TrieNode();
			node->len = max((int) s.length(), node->len);
			node = node->children[c];
		}
		node->words++;
		node->len = max((int) s.length(), node->len);
	}
};

class Solution {
public:
	string longestWord(vector<string>& words) {
		string longest, word;
		Trie trie(words);
		dfs(trie.root, word, longest);
		return longest;
	}
	
	void dfs(TrieNode* node, string& word, string& longest) {
		// optimization
		if (node->len < longest.length())
			return;
		else if (word.length() > longest.length() || word.length() == longest.length() && word < longest)
			longest = word;
		for (auto& [c, u]: node->children) 
			if (u->words) {
				word += c;
				dfs(u, word, longest);
				word.pop_back();
			}
	}
};