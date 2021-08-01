/*
Problem Statement: https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/
Time: O(n² • log n), amortized O(n²)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class UnionFind {
private:
	int m_components;
	vector<int> link;
public:
	UnionFind(int n) : m_components(n), link(n) {
		iota(link.begin(), link.end(), 0);
	}
	
	int components() {
		return m_components;
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
	
	bool same(int a, int b) {
		return find(a) == find(b);
	}
	
	void unify(int a, int b) {
		a = find(a);
		b = find(b);
		// belong to the same component
		if (a == b)
			return;
		link[b] = a;
		m_components--;
	}
};

class Solution {
public:
	int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
		int cnt = 0;
		UnionFind dsu_a(n + 1), dsu_b(n + 1);
		
		for (vector<int>& e: edges) {
			int t, u, v;
			tie(t, u, v) = {e[0], e[1], e[2]};
			if (t != 3)
				continue;
			if (dsu_a.same(u, v))
				cnt++;
			else {
				dsu_a.unify(u, v);
				dsu_b.unify(u, v);
			}
		}
		
		for (vector<int>& e: edges) {
			int t, u, v;
			tie(t, u, v) = {e[0], e[1], e[2]};
			if (t == 1) {
				if (dsu_a.same(u, v))
					cnt++;
				else
					dsu_a.unify(u, v);
			} else if (t == 2) {
				if (dsu_b.same(u, v))
					cnt++;
				else
					dsu_b.unify(u, v);
			}
		}
		
		if (dsu_a.components() > 2 || dsu_b.components() > 2)
			return -1;
		
		return cnt;
	}
};