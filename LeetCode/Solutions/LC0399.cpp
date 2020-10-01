/*
Problem Statement: https://leetcode.com/problems/evaluate-division/
Time: O((n + q) • m)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class UnionFind {
private:
	unordered_map<string, pair<string, double>> link;
public:
	pair<string, double> find(string x) {
		string y, z;
		double a, b;
		
		if (!link.count(x))
			link[x] = {x, 1.0};
		tie(y, a) = link[x];
		
		if (x == y)
			return {y, a};
		tie(z, b) = find(y);
		
		return link[x] = {z, a * b};
	}
	
	void unify(string a, string b, double v) {
		string pa, pb;
		double va, vb;
		
		tie(pa, va) = find(a);
		tie(pb, vb) = find(b);
		
		if (pa != pb)
			link[pa] = {pb, vb / va * v};
	}
	
	double query(string a, string b) {
		string pa, pb;
		double va, vb;
		
		if (!link.count(a) || !link.count(b))
			return -1.0;
		
		tie(pa, va) = find(a);
		tie(pb, vb) = find(b);
		
		if (pa == pb)
			return va / vb;
		else
			return -1.0;
	}
};

class Solution {
public:
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		UnionFind dsu;
		vector<double> res;
		int m = equations.size(), q = queries.size();
		
		for (int i = 0; i < m; i++)
			dsu.unify(equations[i][0], equations[i][1], values[i]);
		
		for (vector<string>& eq: queries)
			res.push_back(dsu.query(eq[0], eq[1]));
		
		return res;
	}
};