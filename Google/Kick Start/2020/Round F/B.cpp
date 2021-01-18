#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int metal_harvest(int N, int K, vector<pair<int, int>>& E) {
	int robots, beg, need;
	robots = beg = 0;
	
	sort(E.begin(), E.end());
	
	for (int i = 0; i < N; i++) {
		if (beg >= E[i].second)
			continue;
		beg = max(E[i].first, beg);
		need = (E[i].second - beg + K - 1) / K;
		robots += need;
		beg += need * K;
	}
	
	return robots;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int N, K;
		cin >> N >> K;
		vector<pair<int, int>> E(N);
		for (int i = 0; i < N; i++)
			cin >> E[i].first >> E[i].second;
		cout << "Case #" << x << ": " << metal_harvest(N, K, E) << endl;
	}
	return 0;
}