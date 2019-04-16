#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int peak(int T, vector<int> &times) {
	int max_t = 0;
	sort(times.begin(), times.end());
	for (int i = 0, j = 0; j < times.size(); j++) {
		while (times[j] - times[i] >= T)
			i++;
		max_t = max(j - i + 1, max_t);
	}
	return max_t;
}

int main() {
	freopen("peak.in", "r", stdin);
	freopen("output.out", "w", stdout);

	int C, k = 1;
	cin >> C;
	while (C--) {
		int N, T;
		cin >> N >> T;
		vector<int> times(N);
		for (int i = 0; i < N; i++)
			cin >> times[i];
		cout << k << ". " << peak(T, times) << endl;
		k++;
	}

	return 0;
}