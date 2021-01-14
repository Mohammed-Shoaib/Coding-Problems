#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longest_arithmetic(int N, vector<int>& A) {
	int max_len, len, diff;
	max_len = len = 2;
	diff = A[1] - A[0];
	
	for (int i = 2; i < N; i++) {
		if (A[i] - A[i - 1] == diff)
			len++;
		else
			len = 2;
		diff = A[i] - A[i - 1];
		max_len = max(len, max_len);
	}
	
	return max_len;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int N;
		cin >> N;
		vector<int> A(N);
		for (int i = 0; i < N; i++)
			cin >> A[i];
		cout << "Case #" << x << ": " << longest_arithmetic(N, A) << endl;
	}
	return 0;
}