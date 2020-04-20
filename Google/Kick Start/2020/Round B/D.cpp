#include <iostream>
#include <iomanip>
#include <functional>

using namespace std;

// passes test set 1
double wandering_robot(int W, int H, int L, int U, int R, int D) {
	double dp[H][W] = {};
	--L, --U, --R, --D;

	// helper function
	auto inside = [&](int x, int y) {
		return U <= x && x <= D && L <= y && y <= R;
	};

	// initialization
	dp[0][0] = 1.0;
	for (int i = 1; i < W && !inside(0, i); i++) {
		if (H == 1)
			dp[0][i] = dp[0][i - 1];
		else
			dp[0][i] = dp[0][i - 1] / 2.0;
	}
	for (int i = 1; i < H && !inside(i, 0); i++) {
		if (W == 1)
			dp[i][0] = dp[i - 1][0];
		else
			dp[i][0] = dp[i - 1][0] / 2.0;
	}

	// dynamic programming
	for (int i = 1; i < H; i++)
		for (int j = 1; j < W; j++) {
			if (inside(i, j))
				continue;
			if (i == H - 1)
				dp[i][j] += dp[i][j - 1];
			else
				dp[i][j] += dp[i][j - 1] / 2.0;
			if (j == W - 1)
				dp[i][j] += dp[i - 1][j];
			else
				dp[i][j] += dp[i - 1][j] / 2.0;
		}

	return dp[H - 1][W - 1];
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int W, H, L, U, R, D;
		cin >> W >> H >> L >> U >> R >> D;
		cout << "Case #" << x << ": ";
		cout << fixed << setprecision(6) << wandering_robot(W, H, L, U, R, D) << endl;
	}
	return 0;
}