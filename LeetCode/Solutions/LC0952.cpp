/*
Problem Statement: https://leetcode.com/problems/largest-component-size-by-common-factor/
Time: O(n • sqrt(m))
Space: O(m)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class UnionFind {
private:
	vector<int> link;
public:
	UnionFind(int n) : link(n) {
		iota(link.begin(), link.end(), 0);
	}
	
	int find(int x) {
		int y = x;
		// find the root of component
		while (x != link[x])
			x = link[x];
		// path compression
		while (y != x)
			y = exchange(link[y], x);
		return x;
	}
	
	void unify(int a, int b) {
		a = find(a);
		b = find(b);
		link[b] = a;
	}
};

class Solution {
public:
	int largestComponentSize(vector<int>& A) {
		int n, m, max_len;
		n = A.size();
		m = *max_element(A.begin(), A.end());
		max_len = 0;
		UnionFind dsu(m + 1);
		vector<int> cnt(m + 1);
		
		// prime factorization
		for (int x: A) {
			int a = x;
			for (int y = 2; y * y <= x; y++) {
				if (x % y != 0)
					continue;
				while (x % y == 0)
					x /= y;
				dsu.unify(y, a);
			}
			if (x > 1)
				dsu.unify(x, a);
		}
		
		// get size of largest component
		for (int x: A)
			max_len = max(++cnt[dsu.find(x)], max_len);
		
		return max_len;
	}
};