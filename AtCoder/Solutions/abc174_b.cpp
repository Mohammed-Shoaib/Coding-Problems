// Problem Code: abc174_b

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int distance(long long D, vector<pair<long long, long long>>& P) {
	return count_if(P.begin(), P.end(), [&D](auto& p) {
		return p.first * p.first + p.second * p.second <= D * D;
	});
}

int main() {
	int N, D;
	cin >> N >> D;
	vector<pair<long long, long long>> P(N);
	for (int i = 0; i < N; i++)
		cin >> P[i].first >> P[i].second;
	cout << distance(D, P);
	return 0;
}