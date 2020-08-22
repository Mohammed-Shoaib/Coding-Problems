/*
Problem Statement: https://leetcode.com/problems/implement-trie-prefix-tree/
*/

class TrieNode {
public:
	int words;
	unordered_map<char, TrieNode*> children;
	TrieNode() : words(0) {}
};

class Trie {
private:
	TrieNode* root;
public:
	Trie() : root(new TrieNode()) {}
	
	void insert(string word) {
		TrieNode* node = root;
		for (char& c: word) {
			if (!node->children.count(c))
				node->children[c] = new TrieNode();
			node = node->children[c];
		}
		node->words++;
	}
	
	bool search(string word) {
		TrieNode* node = root;
		for (char& c: word) {
			if (!node->children.count(c))
				return false;
			node = node->children[c];
		}
		return node->words;
	}
	
	bool startsWith(string prefix) {
		TrieNode* node = root;
		for(char& c: prefix) {
			if (!node->children.count(c))
				return false;
			node = node->children[c];
		}
		return true;
	}
};