/*
Problem Statement: https://leetcode.com/problems/stream-of-characters/
Space: O(len • words + queries)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib

|----------------------|----------------|-------|
| Operations           | Time           | Space |
|----------------------|----------------|-------|
| StreamChecker(words) | O(len • words) | O(1)  |
| add(word)            | O(len)         | O(1)  |
| query(letter)        | O(len)         | O(1)  |
|----------------------|----------------|-------|
*/

class TrieNode {
public:
	int words;
	vector<TrieNode*> children;
	
	TrieNode() : words(0), children(26) {}
};

class StreamChecker {
private:
	int max_len;
	deque<char> d;
	TrieNode* root;
public:
	StreamChecker(vector<string>& words) : max_len(0), root(new TrieNode()) {
		for (string& word: words)
			add(word);
	}
	
	void add(string& word) {
		TrieNode* node = root;
		int len = word.length();
		max_len = max(len, max_len);
		
		for (int i = len - 1; i >= 0; i--) {
			int pos = word[i] - 'a';
			if (!node->children[pos])
				node->children[pos] = new TrieNode();
			node = node->children[pos];
		}
		
		node->words++;
	}
	
	bool query(char letter) {
		d.push_front(letter);
		TrieNode* node = root;
		
		if (d.size() > max_len)
			d.pop_back();
		
		for (char& c: d) {
			if (node->words)
				break;
			else if (!node->children[c - 'a'])
				return false;
			node = node->children[c - 'a'];
		}
		
		return node->words;
	}
};