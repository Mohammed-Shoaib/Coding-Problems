/*
Problem Statement: https://leetcode.com/problems/design-hashmap/
Time: O(n), average O(1)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class MyHashMap {
private:
	int prime;
	vector<list<pair<int, int>>> table;

	int hash(int key) {
		return key % prime;
	}

	list<pair<int, int>>::iterator search(int key) {
		int h = hash(key);
		return find_if(table[h].begin(), table[h].end(), [&key](pair<int, int>& p) {
			return p.first == key;
		});
	}

public:
	MyHashMap() : prime(10007), table(prime) {}
	
	void put(int key, int value) {
		int h = hash(key);
		auto it = search(key);
		if (it != table[h].end())
			it->second = value;
		else
			table[h].emplace_back(key, value);
	}
	
	int get(int key) {
		int h = hash(key);
		auto it = search(key);
		if (it != table[h].end())
			return it->second;
		else
			return -1;
	}
	
	void remove(int key) {
		int h = hash(key);
		auto it = search(key);
		if (it != table[h].end())
			table[h].erase(it);
	}
};