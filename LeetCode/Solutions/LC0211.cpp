/*
Problem Statement: https://leetcode.com/problems/add-and-search-word-data-structure-design/
Space: O(len • words)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib

|---------------|----------------|----------------|
| Operations    | Time           | Space          |
|---------------|----------------|----------------|
| addWord(word) | O(len)         | O(1)           |
| search(word)  | O(len • words) | O(len • words) |
|---------------|----------------|----------------|
*/

class TrieNode {
public:
	int words;
	unordered_map<char, TrieNode*> children;
	
	TrieNode() : words(0) {}
};

class WordDictionary {
private:
	TrieNode* root;
	
	bool search(const string& word, TrieNode* node, int pos = 0) {
		if (pos == word.length())
			return node->words;
		else if (word[pos] != '.')
			return node->children.count(word[pos]) && search(word, node->children[word[pos]], pos + 1);
		for (auto& [c, child]: node->children)
			if (search(word, child, pos + 1))
				return true;
		return false;
	}
	
public:
	WordDictionary() : root(new TrieNode()) {}
	
	void addWord(string word) {
		TrieNode* node = root;
		for (char& c: word) {
			if (!node->children.count(c))
				node->children[c] = new TrieNode();
			node = node->children[c];
		}
		node->words++;
	}
	
	bool search(string word) {
		return search(word, root);
	}
};