/*
Problem Statement: https://leetcode.com/problems/kth-ancestor-of-a-tree-node/
*/

class TreeAncestor {
private:
	int limit;
	vector<vector<int>> anc;
public:
	TreeAncestor(int n, vector<int>& parent) : limit(18), anc(n, vector<int>(limit)) {
		// initialization
		for (int i = 0; i < n; i++)
			anc[i][0] = parent[i];
		
		// pre-process
		for (int b = 1; b < limit; b++)
			for (int i = 0; i < n; i++) {
				int par = anc[i][b - 1];
				if (par == -1)
					anc[i][b] = -1;
				else
					anc[i][b] = anc[par][b - 1];
			}
	}
	
	int getKthAncestor(int node, int k) {
		// binary lifting
		for (int b = 0; b < limit && node != -1; b++)
			if ((k >> b) & 1)
				node = anc[node][b];
		return node;
	}
};