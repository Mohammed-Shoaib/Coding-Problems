#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

double closest_pick(int N, int K, vector<int>& P) {
	int max_gap, sum;
	max_gap = sum = 0;
	priority_queue<int, vector<int>, greater<int>> pq;
	
	// preprocess
	P.push_back(0);
	P.push_back(K + 1);
	N = P.size();
	sort(P.begin(), P.end());
	
	for (int i = 1; i < N; i++) {
		int gap = max(0, P[i] - P[i - 1] - 1);
		max_gap = max(gap, max_gap);
		if (i > 1 && i + 1 < N)
			gap = (gap + 1 ) / 2;
		pq.push(gap);
		if (pq.size() > 2)
			pq.pop();
	}
	
	while (!pq.empty()) {
		sum += pq.top();
		pq.pop();
	}
	
	return (double) max(max_gap, sum) / K;
}

int main() {
	cout << fixed << setprecision(6);
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int N, K;
		cin >> N >> K;
		vector<int> P(N);
		for (int& x: P)
			cin >> x;
		cout << "Case #" << x << ": " << closest_pick(N, K, P) << endl;
	}
	return 0;
}