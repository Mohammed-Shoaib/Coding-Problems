/*
Problem Statement: https://leetcode.com/problems/insert-delete-getrandom-o1/
*/

class RandomizedSet {
private:
	mt19937 gen;
	vector<int> v;
	unordered_map<int, int> m;
public:
	RandomizedSet() : gen(random_device{}()) {}
	
	bool insert(int val) {
		if (m.count(val))
			return false;
		m[val] = v.size();
		v.push_back(val);
		return true;
	}
	
	bool remove(int val) {
		if (!m.count(val))
			return false;
		int pos = m[val];
		v[pos] = v.back();
		m[v[pos]] = pos;
		m.erase(val);
		v.pop_back();
		return true;
	}

	int getRandom() {
		int pos = uniform_int_distribution<int>{0, (int) v.size() - 1}(gen);
		return v[pos];
	}
};