#include <iostream>
#include <vector>

using namespace std;

int countdown(int N, int K, vector<int>& A) {
	int cnt = 0, t = K;
	for (int& num: A) {
		if (num != t)
			t = K;
		if (num == t) {
			t--;
			if (t == 0)
				cnt++;
		}
	}
	return cnt;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int N, K;
		cin >> N >> K;
		vector<int> A(N);
		for (int i = 0; i < N; i++)
			cin >> A[i];
		cout << "Case #" << x << ": " << countdown(N, K, A) << endl;
	}
	return 0;
}