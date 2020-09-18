/*
Problem Statement: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
Time: O(n • 32)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class TrieNode {
public:
	vector<TrieNode*> children;
	
	TrieNode() : children(2) {}
};

class Trie {
private:
	TrieNode* root;
public:
	Trie() : root(new TrieNode()) {}
	
	void insert(int num) {
		TrieNode* node = root;
		for (int i = 31; i >= 0; i--) {
			int b = (num >> i) & 1;
			if (!node->children[b])
				node->children[b] = new TrieNode();
			node = node->children[b];
		}
	}
	
	int match(int num) {
		int best = 0;
		TrieNode* node = root;
		for (int i = 31; i >= 0; i--) {
			int b = (num >> i) & 1;
			if (!node->children[b])
				b ^= 1;
			best ^= b << i;
			node = node->children[b];
		}
		return best;
	}
};

class Solution {
public:
	int findMaximumXOR(vector<int>& nums) {
		Trie trie;
		int max_x = 0;
		for (int& x: nums)
			trie.insert(x);
		for (int& x: nums)
			max_x = max(x ^ trie.match(~x), max_x);
		return max_x;
	}
};