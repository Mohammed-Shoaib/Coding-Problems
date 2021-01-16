#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#include <utility>

using namespace std;

void toys(int N, vector<int>& E, vector<int>& R) {
	int best_toys, remove_toys;
	long long max_len, curr_len, sum;
	priority_queue<pair<int, int>> pq;
	
	// initialization
	best_toys = remove_toys = 0;
	max_len = curr_len = sum = accumulate(E.begin(), E.end(), 0L);
	
	// go through all toys
	for (int i = 0; i < N; i++) {
		curr_len += E[i];
		pq.push({R[i] + E[i], i});
		
		// remove toys that violate
		while (!pq.empty() && pq.top().first > sum) {
			int pos = pq.top().second;
			pq.pop();
			remove_toys++;
			sum -= E[pos];
			curr_len -= 2 * E[pos];
		}
		
		// update maximum length
		if (curr_len > max_len) {
			max_len = curr_len;
			best_toys = remove_toys;
		}
	}
	
	if (pq.empty())
		cout << best_toys << " " << max_len << endl;
	else
		cout << remove_toys << " INDEFINITELY" << endl;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int N;
		cin >> N;
		vector<int> E(N), R(N);
		for (int i = 0; i < N; i++)
			cin >> E[i] >> R[i];
		cout << "Case #" << x << ": ";
		toys(N, E, R);
	}
	return 0;
}