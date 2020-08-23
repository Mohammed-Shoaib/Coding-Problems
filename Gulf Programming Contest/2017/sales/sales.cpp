#include <iostream>
#include <cstdio>
#include <iomanip>
#include <vector>

using namespace std;

double precision = 1000.0;

double sales(int N, int C, vector<double> &W, vector<double> &D) {
	vector<int> V(N);
	vector< vector<int> > dp(N + 1, vector<int>(C + 1));
	for (int i = 0; i < N; i++)
		V[i] = W[i] / (1.0 - D[i]) - W[i];
	for (int i = 1; i <= N; i++)
		for (int w = 1; w <= C; w++) {
			if (W[i - 1] > w)
				dp[i][w] = dp[i - 1][w];
			else
				dp[i][w] = max(dp[i - 1][w - W[i - 1]] + V[i - 1], dp[i - 1][w]);
		}
	return dp[N][C] / precision;
}

int main() {
	freopen("sales.in", "r", stdin);
	freopen("output.out", "w", stdout);
	cout << setprecision(1) << fixed;
	
	int T;
	cin >> T;
	while (T--) {
		int N;
		double C;
		cin >> C >> N;
		vector<double> W(N), D(N);
		C *= precision;
		for (int i = 0; i < N; i++) {
			cin >> W[i] >> D[i];
			D[i] /= 100;
			W[i] *= precision;
		}
		cout << sales(N, C, W, D) << endl;
	}
	
	return 0;
}