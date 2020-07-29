/*
Problem Statement: https://www.facebook.com/codingcompetitions/hacker-cup/2020/qualification-round/problems/C
Time: O(n log n)
Space: O(n)
Author: Mohammed Shoaib, github.com/Mohammed-Shoaib
*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

long long timber(int N, vector<pair<int, int>>& P) {
	long long max_l = 0;
	unordered_map<int, long long> dp;
	sort(P.begin(), P.end());

	for (auto& [p, h]: P) {
		dp[p + h] = max(dp[p] + h, dp[p + h]);
		dp[p] = max(dp[p - h] + h, dp[p]);
		max_l = max({dp[p + h], dp[p], max_l});
	}

	return max_l;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int N;
		cin >> N;
		vector<pair<int, int>> P(N);
		for (int i = 0; i < N; i++)
			cin >> P[i].first >> P[i].second;
		cout << "Case #" << x << ": " << timber(N, P) << endl;
	}
	return 0;
}