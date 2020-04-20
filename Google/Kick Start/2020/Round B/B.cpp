#include <iostream>
#include <vector>

using namespace std;

long long bus_routes(int N, long long D, vector<long long>& X) {
	for (int i = N - 1; i >= 0; i--)
		D = X[i] * (D / X[i]);
	return D;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int N;
		long long D;
		cin >> N >> D;
		vector<long long> X(N);
		for (int i = 0; i < N; i++)
			cin >> X[i];
		cout << "Case #" << x << ": " << bus_routes(N, D, X) << endl;
	}
	return 0;
}