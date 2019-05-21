// Problem Code: FROGV

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void preprocess(int K, vector<int> &D, vector< pair<int, int> > &X) {
	sort(X.rbegin(), X.rend());

	// Base Case
	D[X[0].second] = X[0].first + K;

	// DP
	for (int i = 1; i < X.size(); i++) {
		if (X[i - 1].first - X[i].first <= K)
			D[X[i].second] = D[X[i - 1].second];
		else
			D[X[i].second] = X[i].first + K;
	}
}

string chefAndFrogs(int A, int B, vector<int> &D) {
	return (D[A] == D[B]) ? "Yes" : "No";
}

int main() {
	int N, K, P, A, B;
	cin >> N >> K >> P;
	vector<int> D(N + 1);
	vector< pair<int, int> > X(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> X[i].first;
		X[i].second = i;
	}
	preprocess(K, D, X);
	while (P--) {
		cin >> A >> B;
		cout << chefAndFrogs(A, B, D) << endl;
	}
	return 0;
}