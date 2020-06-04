#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long perfect_subarray(int N, vector<int>& A) {
	int mn, mx;
	mn = mx = 0;
	long long perfect = 0;
	vector<int> prefix(N + 1);

	// construct prefix sum array
	for (int i = 0; i < N; i++) {
		prefix[i + 1] = A[i] + prefix[i];
		mn = min(prefix[i + 1], mn);
		mx = max(prefix[i + 1], mx);
	}
	vector<int> freq(mx - mn + 1);

	// sum over each subarray
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j * j < freq.size(); j++) {
			int comp = prefix[i] - j * j - mn;
			if (comp < 0)
				break;
			perfect += freq[comp];
		}
		freq[prefix[i] - mn]++;
	}

	return perfect;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int N;
		cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; i++)
			cin >> A[i];
		cout << "Case #" << x << ": " << perfect_subarray(N, A) << endl;
	}
	return 0;
}