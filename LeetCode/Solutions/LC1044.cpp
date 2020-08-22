/*
Problem Statement: https://leetcode.com/problems/longest-duplicate-substring/
Time: O(n² • log n), amortized O(n • log n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class RabinKarp {
private:
	int hash, mod;
	long long d, p;
public:
	RabinKarp(const string& pat) : hash(0), mod(1e9 + 7), d(26), p(1) {
		int m = pat.length();
		for (char c: pat)
			hash = (d * hash + (c - 'a')) % mod;
		for (int i = 0; i < m - 1; i++)
			p = (d * p) % mod;
	}
	
	void push(char& c1, char& c2) {
		hash = (hash - p * (c1 - 'a')) % mod;
		if (hash < 0)
			hash += mod;
		hash = (d * hash + (c2 - 'a')) % mod;
	}
	
	int get_hash() {
		return hash;
	}
};

class Solution {
public:
	string longestDupSubstring(string S) {
		string dup;
		int n, low, mid, high;
		low = 0;
		high = n = S.length();
		
		// helper function
		auto good = [&](int x) {
			RabinKarp rk(S.substr(0, x));
			unordered_map<int, vector<int>> m;
			m[rk.get_hash()].push_back(0);
			
			for (int i = x; i < n; i++) {
				rk.push(S[i - x], S[i]);
				auto it = m.find(rk.get_hash());
				if (it != m.end()) {				// found hash in map
					string s = S.substr(i - x + 1, x);
					for (int j: it->second)
						if (s == S.substr(j, x)) {	// make sure it is not a collision
							dup = S.substr(i - x + 1, x);
							return true;
						}
				}
				m[rk.get_hash()].push_back(i - x + 1);
			}
			
			return false;
		};
		
		// binary search
		while (low < high) {
			mid = (low + high) / 2;
			if (good(mid))
				low = mid + 1;
			else
				high = mid;
		}
		
		return dup;
	}
};