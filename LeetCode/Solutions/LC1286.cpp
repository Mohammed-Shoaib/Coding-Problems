/*
Problem Statement: https://leetcode.com/problems/iterator-for-combination/
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib

|------------|------|-------|
| Operations | Time | Space |
|------------|------|-------|
| next()     | O(m) | O(m)  |
| hasNext()  | O(1) | O(1)  |
|------------|------|-------|
*/

class CombinationIterator {
private:
	int m, n;
	vector<int> pos;
	string characters;
public:
	CombinationIterator(string characters, int combinationLength) 
		: m(combinationLength), n(characters.length()), pos(m, -1), characters(characters) {}
	
	void increment() {
		int i = m - 1;
		
		// first time, create combination
		if (pos[i] == -1) {
			iota(pos.begin(), pos.end(), 0);
			return;
		}
		
		// find the position which can be incremented
		for (int j = 1; i > 0 && n - pos[i] - j == 0; j++)
			i--;
		
		// get next combination
		pos[i]++;
		for (int j = i + 1; j < m; j++)
			pos[j] = pos[j - 1] + 1;
	}
	
	string next() {
		string comb;
		increment();
		for (int& i: pos)
			comb += characters[i];
		return comb;
	}
	
	bool hasNext() {
		return n - pos[0] != pos.size();
	}
};