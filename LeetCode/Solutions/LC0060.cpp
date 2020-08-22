/*
Problem Statement: https://leetcode.com/problems/permutation-sequence/
*/

class Solution {
public:
	string getPermutation(int n, int k) {
		string s, t(n, '?');
		vector<int> fact(n + 1);
		
		// preprocess
		fact[0] = 1;
		for (int i = 1; i <= n; i++)
			fact[i] = i * fact[i - 1];
		iota(t.begin(), t.end(), '1');
		
		// compute value at position
		for (int i = n - 1; i >= 0; i--) {
			int pos = (k - 1) / fact[i];
			k -= pos * fact[i];
			s += t[pos];
			t.erase(t.begin() + pos);
		}
		
		return s;
	}
};