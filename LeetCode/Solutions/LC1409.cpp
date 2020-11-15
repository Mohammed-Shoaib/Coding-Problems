/*
Problem Statement: https://leetcode.com/problems/queries-on-a-permutation-with-key/
Time: O(m • log m)
Space: O(m)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

class FenwickTree {
private:
	std::vector<int> ft;
public:
	FenwickTree(int n) : ft(n + 1) {}

	int LSB(int x) {
		return x & (-x);
	}

	void add(int i, int val) {
		while (i < ft.size()) {
			ft[i] += val;
			i += LSB(i);
		}
	}

	int rsq(int i) {
		int sum = 0;
		while (i) {
			sum += ft[i];
			i -= LSB(i);
		}
		return sum;
	}
};

class Solution {
public:
	vector<int> processQueries(vector<int>& queries, int m) {
		int n = queries.size();
		vector<int> res(n);
		FenwickTree ft(n + m + 1);
		vector<int> mp(m + 1);

		for (int i = 1; i <= m; i++) {
			ft.add(n + i, 1);
			mp[i] = n + i;
		}

		for (int i = 0; i < queries.size(); i++) {
			int q = queries[i];
			res[i] = ft.rsq(mp[q]) - 1;
			ft.add(mp[q], -1);
			ft.add(n - i, 1);
			mp[q] = n - i;
		}

		return res;
	}
};