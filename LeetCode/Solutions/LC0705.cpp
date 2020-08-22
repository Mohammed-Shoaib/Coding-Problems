/*
Problem Statement: https://leetcode.com/problems/design-hashset/
Time: O(n), average O(1)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class MyHashSet {
private:
	int prime;
	vector<list<int>> table;
	
	int hash(int key) {
		return key % prime;
	}
	
	list<int>::iterator search(int key) {
		int h = hash(key);
		return find(table[h].begin(), table[h].end(), key);
	}
	
public:
	MyHashSet() : prime(10007), table(prime) {}
	
	void add(int key) {
		int h = hash(key);
		if (!contains(key))
			table[h].push_back(key);
	}
	
	void remove(int key) {
		int h = hash(key);
		auto it = search(key);
		if (it != table[h].end())
			table[h].erase(it);
	}
	
	bool contains(int key) {
		int h = hash(key);
		return search(key) != table[h].end();
	}
};