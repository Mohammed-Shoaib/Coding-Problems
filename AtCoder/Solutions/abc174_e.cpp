// Problem Code: abc174_e

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int logs(int N, int K, vector<int>& A) {
	int low, mid, high;
	low = 1;
	high = *max_element(A.begin(), A.end());

	// helper function
	auto good = [&](int len) {
		long long cuts = 0;
		for (int& log: A)
			cuts += (log - 1) / len;
		return cuts <= K;
	};

	// binary search
	while (low < high) {
		mid = low + (high - low) / 2;
		if (good(mid))
			high = mid;
		else
			low = mid + 1;
	}

	return high;
}

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; i++)
		cin >> A[i];
	cout << logs(N, K, A);
	return 0;
}