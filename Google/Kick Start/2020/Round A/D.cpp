#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <functional>

using namespace std;

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

	TrieNode* get_root() {
		return root;
	}

	void insert(string& word) {
		TrieNode* node = root;
		for (char& c: word) {
			if (!node->children.count(c))
				node->children[c] = new TrieNode();
			node = node->children[c];
		}
		node->words++;
	}
};

int bundling(int N, int K, vector<string>& words) {
	Trie trie;
	int score = 0;

	// helper function to calculate maximum score
	function<int(TrieNode*, int)> dfs = [&](TrieNode* node, int level) {
		int k, prefix = node->words;
		for (auto& it: node->children)
			prefix += dfs(it.second, level + 1);
		score += level * (prefix / K);
		return prefix % K;
	};

	for (string& word: words)
		trie.insert(word);
	dfs(trie.get_root(), 0);
	
	return score;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int N, K;
		cin >> N >> K;
		vector<string> words(N);
		for (int i = 0; i < N; i++)
			cin >> words[i];
		cout << "Case #" << x << ": " << bundling(N, K, words) << endl;
	}
	return 0;
}