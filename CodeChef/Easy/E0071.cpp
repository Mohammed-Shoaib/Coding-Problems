// Problem Code: KINGSHIP

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

long long chefAndKingship(vector<int> P) {
	long long cost = 0;
	int min = distance(P.begin(), min_element(P.begin(), P.end()));
	for (int i = 0 ; i < P.size() ; i++) {
		if (i == min)
			continue;
		cost += (long long) P[i] * P[min];
	}
	return cost;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<int> P(N);
		for (int i = 0 ; i < N ; i++)
			cin >> P[i];
		cout << chefAndKingship(P) << endl;
	}
	return 0;
}