/*
Problem Statement: https://leetcode.com/problems/design-hashmap/
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib

|-----------------|--------------------|-------|
| Operations      | Time               | Space |
|-----------------|--------------------|-------|
| MyHashMap()     | O(1)               | O(1)  |
| put(key, value) | O(n), average O(1) | O(1)  |
| get(key)        | O(n), average O(1) | O(1)  |
| remove(key)     | O(n), average O(1) | O(1)  |
|-----------------|--------------------|-------|
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