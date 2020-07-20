#include <iostream>
#include <iomanip>
#include <vector>
#include <functional>

using namespace std;

double beauty_of_tree(long long N, int A, int B, vector<int>& parent) {
	double expected = 0;
	vector<int> ancestors;
	vector<vector<int>> adj(N);
	vector<vector<int>> dp(N, vector<int>(2, 1));
	
	function<void(int, int)> dfs = [&](int s, int a_or_b) {
		// keep track of ancestors
		ancestors.push_back(s);
		for (int& u: adj[s])
			dfs(u, a_or_b);
		ancestors.pop_back();
		
		// compute sum for parent
		int n, steps;
		n = ancestors.size();
		steps = (a_or_b) ? B : A;
		if (n >= steps)
			dp[ancestors[n - steps]][a_or_b] += dp[s][a_or_b];
	};

	// preprocess
	for (int i = 1; i < N; i++)
		adj[parent[i]].push_back(i);
	dfs(0, 0);
	dfs(0, 1);
	
	// inclusion-exclusion
	for (int i = 0; i < N; i++) {
		expected += dp[i][0] * N;
		expected += dp[i][1] * N;
		expected -= (long long) dp[i][0] * dp[i][1];
	}
	expected /= N * N;
	
	return expected;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int N, A, B;
		cin >> N >> A >> B;
		vector<int> parent(N);
		for (int i = 1; i < N; i++) {
			cin >> parent[i];
			parent[i]--;
		}
		cout << "Case #" << x << ": " << fixed << setprecision(6) << beauty_of_tree(N, A, B, parent) << endl;
	}
	return 0;
}