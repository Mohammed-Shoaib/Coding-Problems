/*
Problem Statement: https://leetcode.com/problems/lfu-cache/
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib

|--------------------|------|-------|
| Operations         | Time | Space |
|--------------------|------|-------|
| LFUCache(capacity) | O(1) | O(1)  |
| get(key)           | O(1) | O(1)  |
| put(key, value)    | O(1) | O(1)  |
|--------------------|------|-------|
*/

class LFUCache {
private:
	class Node {
	public:
		int key, val, freq;
		Node(int key, int val) : key(key), val(val), freq(0) {}
	};

	int min_freq, capacity;
	list<Node> cache;
	unordered_map<int, list<Node>> freq;
	unordered_map<int, list<Node>::iterator> m;
public:
	LFUCache(int capacity) : min_freq(0), capacity(capacity) {}
	
	int get(int key) {
		if (!m.count(key))
			return -1;
		Node node = *m[key];
		freq[node.freq].erase(m[key]);
		if (node.freq == min_freq && freq[node.freq].size() == 0)
			min_freq++;
		freq[++node.freq].push_front(node);
		m[key] = freq[node.freq].begin();
		return node.val;
	}
	
	void put(int key, int value) {
		if (capacity == 0)
			return;
		else if (m.count(key)) {
			m[key]->val = value;
			get(key);
			return;
		}
		
		Node node(key, value);
		freq[node.freq].push_front(node);
		m[key] = freq[node.freq].begin();
		if (m.size() > capacity) {
			m.erase(freq[min_freq].back().key);
			freq[min_freq].pop_back();
		}
		min_freq = node.freq;
	}
};