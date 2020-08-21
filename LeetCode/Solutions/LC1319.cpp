/*
Problem Statement: https://leetcode.com/problems/number-of-operations-to-make-network-connected/
Time: O(n + m • log n), amortized O(n + m)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class UnionFind {
private:
	int m_components;
	vector<int> link, size;
public:
	UnionFind(int n) : m_components(n), link(n), size(n, 1) {
		iota(link.begin(), link.end(), 0);
	}
	
	int find(int x) {
		int y = x;
		// find the root of component
		while (x != link[x])
			x = link[x];
		// path compression
		while (y != x)
			y = std::exchange(link[y], x);
		return x;
	}
	
	bool same(int a, int b) {
		return find(a) == find(b);
	}
	
	void unify(int a, int b) {
		a = find(a);
		b = find(b);
		if (a == b)
			return;
		if (size[a] < size[b])
			swap(a, b);
		link[b] = a;
		size[a] += size[b];
		m_components--;
	}
	
	int components() {
		return m_components;
	}
};

class Solution {
public:
	int makeConnected(int n, vector<vector<int>>& connections) {
		int m = connections.size();
		if (m < n - 1)
			return -1;
		UnionFind dsu(n);
		for (vector<int>& conn: connections)
			dsu.unify(conn[0], conn[1]);
		return dsu.components() - 1;
	}
};