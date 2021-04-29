#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longest_subarray(vector<int>& D) {
	int len = 0, M = D.size();
	
	for (int i = 0, j = 0; i < M; i = j) {
		while (j < M && D[i] == D[j])
			j++;
		len = max(j - i + 1 + (j < M), len);
		
		if (j + 1 < M && D[j] + D[j + 1] == 2 * D[i]) {
			int k = j + 2;
			len = max(k - i, len);
			while (k < M && D[i] == D[k])
				k++;
			len = max(k - i + 1, len);
		}
	}
	
	return len;
}

int longest_progression(int N, vector<int>& A) {
	vector<int> D(N - 1);
	
	for (int i = 0; i < N - 1; i++)
		D[i] = A[i + 1] - A[i];
	
	int max_len = longest_subarray(D);
	reverse(D.begin(), D.end());
	max_len = max(longest_subarray(D), max_len);
	
	return max_len;
}

int main() {
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++) {
		int N;
		cin >> N;
		vector<int> A(N);
		for (int& x: A)
			cin >> x;
		cout << "Case #" << x << ": " << longest_progression(N, A) << endl;
	}
	return 0;
}