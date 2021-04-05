#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int moons_and_umbrellas(int X, int Y, string& S) {
	int INF = 1e9, n = S.length();
	vector<int> dp(2, 1e9);
	
	// initialization
	if (S[0] != 'C')
		dp[1] = 0;
	if (S[0] != 'J')
		dp[0] = 0;
	
	// dynamic programming
	for (int i = 1; i < n; i++) {
		vector<int> prev = exchange(dp, vector<int>(2, INF));
		if (S[i] != 'J')
			dp[0] = min(prev[1] + Y, prev[0]);
		if (S[i] != 'C')
			dp[1] = min(prev[0] + X, prev[1]);
	}
	
	return min(dp[0], dp[1]);
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int X, Y;
		string S;
		cin >> X >> Y >> S;
		cout << "Case #" << x << ": " << moons_and_umbrellas(X, Y, S) << endl;
	}
	return 0;
}