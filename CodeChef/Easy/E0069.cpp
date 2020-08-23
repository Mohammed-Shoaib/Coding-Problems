// Problem Code: CHEFSTON

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

long long chefAndStones(int K, vector<int> A, vector<int> B) {
	long long profit, maxProfit = numeric_limits<long long>::min();
	for (int i = 0 ; i < A.size() ; i++) {
		profit = (long long) (K / A[i]) * B[i];
		if (profit > maxProfit)
			maxProfit = profit;
	}
	return maxProfit;
}

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, K;
		cin >> N >> K;
		vector<int> A(N), B(N);
		for (int i = 0 ; i < N ; i++)
			cin >> A[i];
		for (int i = 0 ; i < N ; i++)
			cin >> B[i];
		cout << chefAndStones(K, A, B) << endl;
	}
	return 0;
}