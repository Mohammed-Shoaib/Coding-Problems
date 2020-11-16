/*
Problem Statement: https://leetcode.com/problems/html-entity-parser/
*/

class TrieNode {
public:
	char symbol;
	unordered_map<char, TrieNode*> children;

	TrieNode() : symbol(0) {}
};

class Trie {
private:
	TrieNode* root;
public:
	Trie() : root(new TrieNode()) {}

	void insert(string entity, char symbol) {
		TrieNode* node = root;
		for (char& c: entity) {
			if (!node->children.count(c))
				node->children[c] = new TrieNode();
			node = node->children[c];
		}
		node->symbol = symbol;
	}

	char search(string& text, int l, int r) {
		TrieNode* node = root;
		for (int i = l; i <= r; i++) {
			char& c = text[i];
			if (!node->children.count(c))
				return 0;
			node = node->children[c];
		}
		return node->symbol;
	}
};

class Solution {
public:
	string entityParser(string text) {
		Trie trie;
		int len = 0;
		unordered_map<string, char> m = {
			{"&gt;", '>'},
			{"&lt;", '<'},
			{"&amp;", '&'},
			{"&quot;", '\"'},
			{"&apos;", '\''},
			{"&frasl;", '/'}
		};

		// insert entities into the trie with symbol
		for (auto& [entity, symbol]: m)
			trie.insert(entity, symbol);
		
		// replace occurrences of entity with symbol using trie
		for (int i = 0, j = 0; i < text.length(); i++, len++) {
			text[len] = text[i];
			if (text[i] == '&')			// start position of entity
				j = len;
			else if (text[i] == ';') {	// end position of entity
				char symbol = trie.search(text, j, len);
				if (symbol != 0) {		// valid entity
					len -= len - j;
					text[len] = symbol;
				}
				j++;
			}
		}
		text.resize(len);

		return text;
	}
};