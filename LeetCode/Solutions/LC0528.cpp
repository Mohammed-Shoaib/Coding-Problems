/*
Problem Statement: https://leetcode.com/problems/random-pick-with-weight/
*/

class Solution {
private:
	mt19937 gen;
	vector<int> prefix;
	uniform_int_distribution<mt19937::result_type> dist;
public:
	Solution(vector<int>& w) : gen(random_device{}()), prefix(w.size()),
							   dist(1, accumulate(w.begin(), w.end(), 0)) {
		partial_sum(w.begin(), w.end(), prefix.begin());
	}
	
	int pickIndex() {
		return distance(prefix.begin(), lower_bound(prefix.begin(), prefix.end(), dist(gen)));
	}
};