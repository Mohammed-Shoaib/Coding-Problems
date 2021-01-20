#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int64_t maximum_coins(int N, vector<vector<int>>& C) {
	vector<int64_t> dp(2 * N - 1);
	
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			dp[i - j + N - 1] += C[i][j];
	
	return *max_element(dp.begin(), dp.end());
}

int main() {
	int T;
	cin >> T;
	
	for (int x = 1; x <= T; x++) {
		int N;
		cin >> N;
		vector<vector<int>> C(N, vector<int>(N));
		
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> C[i][j];
		
		cout << "Case #" << x << ": " << maximum_coins(N, C) << endl;
	}
	
	return 0;
}