/*
Problem Statement: https://leetcode.com/problems/first-unique-number/
*/

class FirstUnique {
private:
	queue<int> q;
	unordered_set<int> seen, uniq;
public:
	FirstUnique(vector<int>& nums) {
		for (int& num: nums)
			add(num);
	}
	
	int showFirstUnique() {
		while (!q.empty() && !uniq.count(q.front()))
			q.pop();
		return q.empty() ? -1 : q.front();
	}
	
	void add(int value) {
		if (seen.count(value)) {
			if (uniq.count(value))
				uniq.erase(value);
			return;
		}
		q.push(value);
		uniq.insert(value);
		seen.insert(value);
	}
};