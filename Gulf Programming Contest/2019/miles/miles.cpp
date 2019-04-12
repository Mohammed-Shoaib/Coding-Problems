#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int miles(int V, vector<int> &T) {
	if (V >= T.size())
		return accumulate(T.begin(), T.end(), 0);
	int max_m, curr_m;
	max_m = curr_m = accumulate(T.begin(), T.begin() + V, 0);
	for (int i = V; i < T.size(); i++) {
		curr_m += T[i];
		curr_m -= T[i - V];
		max_m = max(curr_m, max_m);
	}
	return max_m;
}

int main() {
	freopen("miles.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	int M, V, k = 1;
	while (cin >> M >> V && M && V) {
		vector<int> T(M);
		for (int i = 0; i < M; i++)
			cin >> T[i];
		cout << k << ". " << miles(V, T) << endl;
		k++;
	}

	return 0;
}