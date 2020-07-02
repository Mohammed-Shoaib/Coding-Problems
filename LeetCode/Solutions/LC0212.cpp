/*
Problem Statement: https://leetcode.com/problems/word-search-ii/
Time: O(n • m • (3 ^ len))
Space: O(words • len)
*/

class TrieNode {
public:
	bool end;
	unordered_map<char, TrieNode*> children;

	TrieNode() : end(false) {}

	TrieNode* get_next(char& c) {
		if (children.count(c))
			return children[c];
		else
			return nullptr;
	}
};

class Trie {
public:
	TrieNode* root;

	Trie() : root(new TrieNode()) {}

	void add(string& word) {
		TrieNode* node = root;
		for (char& c: word) {
			if (!node->children.count(c))
				node->children[c] = new TrieNode();
			node = node->children[c];
		}
		node->end = true;
	}

	void build(vector<string>& words) {
		for (string& word: words)
			add(word);
	}
};

class Solution {
public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		int m, n;
		m = board.size();
		n = board[0].size();
		Trie trie;
		string word;
		vector<string> res;
		vector<int> xdir = {-1, 0, 1, 0}, ydir = {0, -1, 0, 1};

		// helper function
		function<void(int, int, TrieNode*)> search = [&](int i, int j, TrieNode* node) {
			// base cases
			if (i < 0 || i == m || j < 0 || j == n || !node->get_next(board[i][j]))
				return;
			
			node = node->get_next(board[i][j]);
			word += exchange(board[i][j], '*');

			for (int k = 0; k < xdir.size(); k++)
				search(i + xdir[k], j + ydir[k], node);
			if (node->end) {
				node->end = false;
				res.push_back(word);
			}

			board[i][j] = word.back();
			word.pop_back();
		};

		trie.build(words);
		
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				search(i, j, trie.root);

		return res;
	}
};