#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int workout(int N, int K, vector<int>& M) {
	int mid, low = 1, high = 1e9;

	// helper function to determine required sessions to add given maximum difficulty d
	function<int(int)> f = [&](int d) {
		int add = 0;
		for (int i = 1; i < N; i++)
			add += (M[i] - M[i - 1] - 1) / d;
		return add;
	};

	// binary search
	while (low < high) {
		mid = (low + high) / 2;
		if (f(mid) <= K)
			high = mid;
		else
			low = mid + 1;
	}

	return high;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int N, K;
		cin >> N >> K;
		vector<int> M(N);
		for (int i = 0; i < N; i++)
			cin >> M[i];
		cout << "Case #" << x << ": " << workout(N, K, M) << endl;
	}
	return 0;
}