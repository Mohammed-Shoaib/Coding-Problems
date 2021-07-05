/*
Problem Statement: https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib

|------------------------|------|-------|
| Operations             | Time | Space |
|------------------------|------|-------|
| RandomizedCollection() | O(1) | O(1)  |
| insert(val)            | O(1) | O(1)  |
| remove(val)            | O(1) | O(1)  |
| getRandom()            | O(1) | O(1)  |
|------------------------|------|-------|
*/

class RandomizedCollection {
private:
	mt19937 gen;
	vector<int> v;
	unordered_map<int, unordered_set<int>> m;
public:
	RandomizedCollection() : gen(random_device{}()) {}

	bool insert(int val) {
		bool exist = m.count(val);
		m[val].insert(v.size());
		v.push_back(val);
		return !exist;
	}

	bool remove(int val) {
		if (!m.count(val))
			return false;
		int pos, ele;

		// assign last element to gap
		auto it = m[val].begin();
		pos = *it;
		ele = v.back();
		v[pos] = ele;

		// remove element
		m[val].erase(it);
		v.pop_back();
		if (!m[ele].empty()) {
			m[ele].erase(v.size());
			m[ele].insert(pos);
		}

		// delete value if empty
		if (m[val].empty())
			m.erase(val);

		return true;
	}

	int getRandom() {
		int pos = uniform_int_distribution<int>{0, (int) v.size() - 1}(gen);
		return v[pos];
	}
};