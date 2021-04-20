#include <iostream>
#include <vector>
#include <tuple>
#include <numeric>
#include <utility>
#include <algorithm>

using namespace std;

class UnionFind {
private:
	vector<int> link, size;
public:
	UnionFind(int n): link(n), size(n, 1) {
		iota(link.begin(), link.end(), 0);
	}
	
	int find(int x) {
		int y = x;
		
		// find the root component
		while (link[x] != x)
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
		
		if (a == b)
			return;
		else if (size[a] < size[b])
			swap(a, b);
		
		link[b] = a;
		size[a] += size[b];
	}
};

int checksum(int N, vector<int>& R, vector<int>& C, vector<vector<int>>& A, vector<vector<int>>& B) {
	int cost = 0;
	UnionFind dsu(2 * N);
	vector<vector<int>> edges;
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (A[i][j] == -1) {
				cost += B[i][j];
				edges.push_back({B[i][j], i, j});
			}
	sort(edges.rbegin(), edges.rend());
	
	for (auto& e: edges) {
		int w, r, c;
		tie(w, r, c) = {e[0], e[1], e[2]};
		if (!dsu.same(r, N + c)) {
			dsu.unify(r, N + c);
			cost -= B[r][c];
		}
	}
	
	return cost;	
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int N;
		cin >> N;
		vector<int> R(N), C(N);
		vector<vector<int>> A(N, vector<int>(N)), B(N, vector<int>(N));
		
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> A[i][j];
		
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> B[i][j];
		
		for (int i = 0; i < N; i++)
			cin >> R[i];
		
		for (int i = 0; i < N; i++)
			cin >> C[i];
		
		cout << "Case #" << x << ": " << checksum(N, R, C, A, B) << endl;
	}
	return 0;
}