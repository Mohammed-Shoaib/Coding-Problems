// Problem Code: abc158_f

#include <iostream>
#include <vector>
#include <limits>
#include <utility>
#include <algorithm>

using namespace std;

int removing_robots(int N, vector<pair<int, int>>& R) {
	int d, mod = 998244353;
	vector<int> dp(N + 1);
	vector<pair<int, int>> st;
	
	dp[N] = 1;
	st.emplace_back(N, numeric_limits<int>::max());
	sort(R.begin(), R.end());

	for (int j, i = N - 1; i >= 0; i--) {
		d = R[i].first + R[i].second;
		while (d > st.back().second)
			st.pop_back();
		j = st.back().first;
		dp[i] = (dp[i + 1] + dp[j]) % mod;
		st.emplace_back(i, R[i].first);
	}

	return dp[0];
}

int main() {
	int N;
	cin >> N;
	vector<pair<int, int>> R(N);
	for (int i = 0; i < N; i++)
		cin >> R[i].first >> R[i].second;
	cout << removing_robots(N, R);
	return 0;
}