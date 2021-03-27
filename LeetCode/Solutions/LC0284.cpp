/*
Problem Statement: https://leetcode.com/problems/peeking-iterator/
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib

|-------------------|------|-------|
| Operations        | Time | Space |
|-------------------|------|-------|
| PeekingIterator() | O(1) | O(1)  |
| next()            | O(1) | O(1)  |
| hasNext()         | O(1) | O(1)  |
|-------------------|------|-------|
*/

class PeekingIterator : public Iterator {
private:
	int cache;
	bool is_cache;
public:
	PeekingIterator(const vector<int>& nums) : is_cache(false), Iterator(nums) {}
	
	int peek() {
		if (exchange(is_cache, true))
			return cache;
		return cache = Iterator::next();
	}
	
	int next() {
		if (exchange(is_cache, false))
			return cache;
		return Iterator::next();
	}
	
	bool hasNext() const {
		return is_cache || Iterator::hasNext();
	}
};