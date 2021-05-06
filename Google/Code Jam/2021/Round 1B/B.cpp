#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <functional>

using namespace std;

string subtransmutation(int N, int A, int B, vector<int>& U) {
	int metal = N, limit = 1000;
	
	// helper function
	auto good = [&](int x) {
		vector<int> cnt(x + 1, 0);
		
		cnt[x] = 1;
		for (int i = x; i > 0; i--) {
			cnt[i] = min(cnt[i], limit);
			if (i <= N)
				cnt[i] -= U[i];
			if (cnt[i] < 0)
				return false;
			if (i > A)
				cnt[i - A] += cnt[i];
			if (i > B)
				cnt[i - B] += cnt[i];
		}
		
		return true;
	};
	
	// binary search
	while (!good(metal) && metal < limit)
		metal++;
	
	return (metal == limit) ? "IMPOSSIBLE" : to_string(metal);
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int N, A, B;
		cin >> N >> A >> B;
		vector<int> U(N + 1);
		for (int i = 1; i <= N; i++)
			cin >> U[i];
		cout << "Case #" << x << ": " << subtransmutation(N, A, B, U) << endl;
	}
	return 0;
}